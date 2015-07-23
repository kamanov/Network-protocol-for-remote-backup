#include "networkcontroller.h"
#include "clientconfiguration.h"
#include "event2/event.h"
#include "event2/bufferevent.h"

NetworkController::NetworkController()
{
}

void NetworkController::send(Message* msg)
{

}

void NetworkController::run()
{
    struct event_base *base;
    base = event_base_new();

    add_connection();
    event_base_dispatch(base);
    event_base_free(base);dd
}

void NetworkController::add_connection(event_base *base)
{
    struct bufferevent *bev;
    struct sockaddr_in sin;

    base = event_base_new();

    ClientConfiguration *cfg = ClientConfiguration::getInstance();
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    //sin.sin_addr.s_addr = htonl(0x7f000001); // 127.0.0.1
    sin.sin_port = htons(cfg->serverInfo().port);

    bev = bufferevent_socket_new(base, -1, BEV_OPT_CLOSE_ON_FREE);

    bufferevent_setcb(bev, readcb, writecb, eventcb, (void *)base);

    if (bufferevent_socket_connect(bev,
        (struct sockaddr *)&sin, sizeof(sin)) < 0) {
        fprintf(stderr, "Error starting connection!\n");
        bufferevent_free(bev);
        return;
    }
    bufferevent_enable(bev, EV_WRITE);
    bufferevent_enable(bev, EV_READ);
}


void NetworkController::eventcb(struct bufferevent *bev, short events, void *ptr)
{
    if (events & BEV_EVENT_CONNECTED) {
        fprintf(stdout, "Connected\n");
        bufferevent_write(bev, MESSAGE, strlen(MESSAGE));
    } else if (events & BEV_EVENT_ERROR) {
        fprintf(stderr, "An error occured while connecting!\n");
        bufferevent_free(bev);
    }
}
/*

void NetworkController::writecb(struct bufferevent *bev, void *ctx) {
    struct evbuffer *output = bufferevent_get_output(bev);
    if (evbuffer_get_length(output) == 0) {
        printf("flushed answer!\n");
        bufferevent_free(bev);
    }
}

void NetworkController::readcb(struct bufferevent *bev, void *ctx) {
    struct evbuffer *output = bufferevent_get_output(bev);
    if (evbuffer_get_length(output) == 0) {
        printf("flushed answer!\n");
        bufferevent_free(bev);
    }
}



*/

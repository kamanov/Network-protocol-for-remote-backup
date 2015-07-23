#include <event2/event.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>

static const char MESSAGE[] = "Hello, World!\n";
static const int SERVER_PORT = 9999;


void eventcb(struct bufferevent *bev, short events, void *ptr)
{
    if (events & BEV_EVENT_CONNECTED) {
        fprintf(stdout, "Connected\n");
        bufferevent_write(bev, MESSAGE, strlen(MESSAGE));
    } else if (events & BEV_EVENT_ERROR) {
        fprintf(stderr, "An error occured while connecting!\n");
        bufferevent_free(bev);
    }
}

void writecb(struct bufferevent *bev, void *ctx) {
    struct evbuffer *output = bufferevent_get_output(bev);
    if (evbuffer_get_length(output) == 0) {
        printf("flushed answer!\n");
        bufferevent_free(bev);
    }
}

int test(int argc, char **argv)
{
    struct event_base *base;
    struct bufferevent *bev;
    struct sockaddr_in sin;

    base = event_base_new();

    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = htonl(0x7f000001); // 127.0.0.1
    sin.sin_port = htons(SERVER_PORT);

    bev = bufferevent_socket_new(base, -1, BEV_OPT_CLOSE_ON_FREE);

    bufferevent_setcb(bev, NULL, writecb, eventcb, (void *)base);

    if (bufferevent_socket_connect(bev,
        (struct sockaddr *)&sin, sizeof(sin)) < 0) {
        fprintf(stderr, "Error starting connection!\n");
        bufferevent_free(bev);
        return -1;
    }
    bufferevent_enable(bev, EV_WRITE);
    bufferevent_disable(bev, EV_READ);

    event_base_dispatch(base);
    return 0;
}

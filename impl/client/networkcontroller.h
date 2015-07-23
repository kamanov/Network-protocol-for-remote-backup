#ifndef NETWORKCONTROLLER_H
#define NETWORKCONTROLLER_H

#include <functional>
#include "messages.h"

class NetworkControllerDelegate;

class NetworkController
{
public:
    NetworkController();
    void send(Message* msg);
    void run();

private:
    void add_connection();
    void eventcb(struct bufferevent *bev, short events, void *ptr);



};

class NetworkControllerDelegate {
    virtual void onMessageReceived(Message* msg) = 0;
};

#endif // NETWORKCONTROLLER_H

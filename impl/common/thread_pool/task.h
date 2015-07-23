#ifndef TASK_H
#define TASK_H
#include "taskhandler.h"
#include "executorservice.h"
#include <boost/thread.hpp>
#include <iostream>

class Task : public TaskHandler
{
public:
    Task(Callable taskCallable);
    virtual void cancel();
    void setThread(boost::thread* thread);
    bool isCanceled();
    void run();
private:
    boost::mutex m_mtx;
    boost::thread* m_thread;
    Callable m_taskCallable;
    bool m_isCanceled;
};
typedef boost::shared_ptr<Task> TaskPtr;

#endif // TASK_H

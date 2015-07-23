#ifndef WORKER_H
#define WORKER_H
#include <boost/thread.hpp>
#include <boost/atomic.hpp>
#include "task.h"
#include "concurrentqueue.h"

class Worker
{
public:
    Worker(ConcurrentQueue<TaskPtr>* queue, size_t waitTime = 0); // waitTime == 0 <=> hot thread
    ~Worker();
    void join() const;
    void interrupt() const;
    void makeInvalid() { m_isValid = false; }
    bool isBusy() const { return m_isBusy; }
    bool isFinished() const { return m_isFinished; }
private:
    boost::atomic<bool> m_isValid;
    boost::atomic<bool> m_isBusy;
    boost::atomic<bool> m_isFinished;
    boost::thread* m_thread;
    size_t m_waitTime;
    ConcurrentQueue<TaskPtr>* m_tasksQueue;
    bool isHot() { return m_waitTime == 0; }
    void startExecution();
};

#endif // WORKER_H

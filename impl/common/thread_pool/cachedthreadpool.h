#ifndef CACHEDTHREADPOOL_H
#define CACHEDTHREADPOOL_H

#include "executorservice.h"
#include "concurrentqueue.h"
#include <queue>
#include <list>
#include <boost/shared_ptr.hpp>
#include "task.h"

class Worker;


class CachedThreadPool : public ExecutorService
{

public:
    CachedThreadPool(size_t hotThreadsNum, size_t timeout);
    boost::shared_ptr<TaskHandler> execute(Callable taskCallable);
    void shutdown();
    ~CachedThreadPool();

private:
    size_t m_WaitTimeout;
    ConcurrentQueue<TaskPtr> m_tasksQueue;
    std::list<Worker*> m_workers;
    bool m_shutdown;
};

#endif // CACHEDTHREADPOOL_H

#include "cachedthreadpool.h"
#include "taskhandler.h"
#include "worker.h"

CachedThreadPool::CachedThreadPool(size_t hotThreadsNum, size_t timeout)
    : m_WaitTimeout(timeout)
    , m_shutdown(false)
{
    for (size_t i = 0; i < hotThreadsNum; i++) {
        m_workers.push_back(new Worker(&m_tasksQueue));
    }
}

boost::shared_ptr<TaskHandler> CachedThreadPool::execute(Callable taskCallable)
{
    auto it = m_workers.begin();
    bool hasFreeWorker = false;
    while (it != m_workers.end())
    {
        Worker* worker = *it;
        if (worker->isFinished()) {
            it = m_workers.erase(it);
            delete worker;
        } else if (!worker->isBusy()) {
            hasFreeWorker = true;
            break;
        } else {
            ++it;
        }
    }
    if (!hasFreeWorker) {
        m_workers.push_back(new Worker(&m_tasksQueue, m_WaitTimeout));
    }
    TaskPtr taskPtr = boost::shared_ptr<Task>(new Task(taskCallable));
    m_tasksQueue.push(taskPtr);
    return boost::static_pointer_cast<TaskHandler>(taskPtr);
}

void CachedThreadPool::shutdown()
{
    if (m_shutdown) return;
    m_shutdown = true;
    m_tasksQueue.clear();
    auto it = m_workers.begin();
    while (it != m_workers.end())
    {
        Worker* worker = *it;
        worker->makeInvalid();
        if (!worker->isBusy()) {
            worker->interrupt();
        }
        worker->join();
        ++it;
    }
}

CachedThreadPool::~CachedThreadPool()
{
    shutdown();
    auto it = m_workers.begin();
    while (it != m_workers.end())
    {
        Worker* worker = *it;
        ++it;
        delete worker;
    }
}


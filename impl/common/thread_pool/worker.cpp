#include "worker.h"

Worker::Worker(ConcurrentQueue<TaskPtr>* queue, size_t waitTime)
    : m_isValid(true)
    , m_isBusy(false)
    , m_isFinished(false)
    , m_waitTime(waitTime)
    , m_tasksQueue(queue)
{
    assert(queue != nullptr);
    m_thread = new boost::thread(boost::bind(&Worker::startExecution, this));
}

Worker::~Worker()
{
    delete m_thread;
}

void Worker::join() const
{
    m_thread->join();
}

void Worker::interrupt() const
{
    m_thread->interrupt();
}

void Worker::startExecution()
{
    while (m_isValid) {
        try {
                m_isBusy = false;
                TaskPtr taskPtr;
                if (isHot())
                    taskPtr = m_tasksQueue->waitAndPop();
                else {
                    bool success = m_tasksQueue->waitForAndPop(m_waitTime, taskPtr);
                    if (!success) {
                        break;
                    }
                }
                m_isBusy = true;
                taskPtr->setThread(m_thread);
                if (taskPtr->isCanceled()) {
                    if (isHot())
                        continue;
                    else
                        break;
                }
                taskPtr->run();
        } catch(boost::thread_interrupted&) {
             if (!isHot()) {
                 break;
             }
        }
    }
    m_isFinished = true;
}

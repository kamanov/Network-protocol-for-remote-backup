#include "task.h"

Task::Task(Callable taskCallable)
    : m_thread(nullptr)
    , m_taskCallable(taskCallable)
    , m_isCanceled(false)
{
}

void Task::cancel()
{
    boost::lock_guard<boost::mutex> lock(m_mtx);
    m_isCanceled = true;
    if (m_thread) {
         m_thread->interrupt();
    }
}

void Task::setThread(boost::thread *thread)
{
    boost::lock_guard<boost::mutex> lock(m_mtx);
    m_thread = thread;
}

bool Task::isCanceled()
{
    boost::lock_guard<boost::mutex> lock(m_mtx);
    return m_isCanceled;
}

void Task::run()
{
    m_taskCallable();
}

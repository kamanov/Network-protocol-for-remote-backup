
template <class T>
T& ConcurrentQueue<T>::ConcurrentQueue::waitAndPop()
{
    boost::unique_lock<boost::mutex> lock(m_mtx);
    while (m_queue.empty()) {
        m_cond.wait(lock);
    }
    T& top = m_queue.front();
    m_queue.pop();

    return top;
}

template <class T>
bool ConcurrentQueue<T>::waitForAndPop(size_t time, T &out)
{
    boost::unique_lock<boost::mutex> lock(m_mtx);
    bool beforeTimeout = true;
    while (m_queue.empty() && beforeTimeout) {
        beforeTimeout = m_cond.timed_wait(lock, boost::posix_time::seconds(time));
    }
    if (!beforeTimeout && m_queue.empty()) {
        return false;
    }
    out = m_queue.front();
    m_queue.pop();
    return true;

}

template <class T>
void ConcurrentQueue<T>::push(T &obj)
{
    boost::unique_lock<boost::mutex> lock(m_mtx);
    m_queue.push(obj);
    lock.unlock();
    m_cond.notify_one();
}

template <class T>
bool ConcurrentQueue<T>::isEmpty() const
{
    boost::lock_guard<boost::mutex> lock(m_mtx);
    return m_queue.empty();
}

template <class T>
void ConcurrentQueue<T>::clear()
{
    boost::lock_guard<boost::mutex> lock(m_mtx);
    std::queue<T> empty;
    std::swap(m_queue, empty);

}

#ifndef CONCURRENTQUEUE_H
#define CONCURRENTQUEUE_H
#include <queue>
#include <boost/thread.hpp>

template<typename T>
class ConcurrentQueue
{
public:
    T& waitAndPop();
    bool waitForAndPop(size_t time, T& out); // return false if time is out, true otherwise
    void push(T& obj);
    bool isEmpty() const;
    void clear();
private:
    std::queue<T> m_queue;
    boost::mutex m_mtx;
    boost::condition_variable m_cond;

};

#include "concurrentqueue_impl.h"

#endif // CONCURRENTQUEUE_H

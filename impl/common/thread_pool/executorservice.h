#ifndef EXECUTORSERVICE_H
#define EXECUTORSERVICE_H

#include <memory>
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>

class TaskHandler;
typedef boost::function<void()> Callable;

class ExecutorService {
public:
    virtual boost::shared_ptr<TaskHandler> execute(Callable) = 0;
    virtual void shutdown() = 0;
    virtual ~ExecutorService() {}
};

#endif // EXECUTORSERVICE_H

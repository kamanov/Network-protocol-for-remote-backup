#ifndef INTERPRETATOR_H
#define INTERPRETATOR_H
#include <stddef.h>
#include <map>
#include "taskhandler.h"
#include <boost/shared_ptr.hpp>


class ExecutorService;
typedef unsigned int task_id;

class Interpretator
{
public:
    void signalHandler( int signum );
    void init(size_t hotThreadsNum, size_t timeout);
    ~Interpretator();
    void run();
private:

    enum COMMAND_TYPE {
        NEW_TASK = 0,
        KILL_TASK
    };
    void emptyTaskWithDuration(int time, task_id id);
    void execAddCommand(int time);
    void execKillCommand(task_id id);
    ExecutorService *m_executor;
    task_id m_nextTaskId;
    std::map<task_id, boost::shared_ptr<TaskHandler>> m_idToHandler;
    bool kill_signal_received;
};

#endif // INTERPRETATOR_H

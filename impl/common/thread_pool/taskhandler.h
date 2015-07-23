#ifndef TASKHANDLER_H
#define TASKHANDLER_H

class TaskHandler
{
public:
    virtual void cancel() = 0;
    virtual ~TaskHandler() {}
};

#endif // TASKHANDLER_H

#include "interpretator.h"
#include "cachedthreadpool.h"
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <boost/thread/thread.hpp>
#include <sstream>
#include <boost/thread/mutex.hpp>
#include <csignal>

static const std::string NEW_TASK_CMD = "add";
static const std::string KILL_TASK_CMD = "kill";

class Printer
{
    static boost::mutex m_mutex;
public:
    static void print(const std::string& str);
};

boost::mutex Printer::m_mutex;

void Interpretator::init(size_t hotThreadsNum, size_t timeout)
{
    m_executor = new CachedThreadPool(hotThreadsNum, timeout);
    m_nextTaskId = 0;
    kill_signal_received = false;
}

void Interpretator::signalHandler(int signum)
{
    if (kill_signal_received) return;
    if (signum == SIGTERM || signum == SIGINT) {
        kill_signal_received = true;
        m_executor->shutdown();
        exit(1);
    }
}

Interpretator::~Interpretator()
{
    delete m_executor;
}


void Interpretator::run()
{
    assert(m_executor != 0);
    std::string command;
    int arg;
    while (std::cin) {
        std::cin >> command >> arg;
        if (std::cin.fail() || !(command == NEW_TASK_CMD || command == KILL_TASK_CMD) || arg < 0) {
            Printer::print("Invalid command\n");
            std::cin.clear();
            continue;
        }
        if (command == NEW_TASK_CMD) {
            execAddCommand(arg);
        } else {
            execKillCommand(arg);
        }
    }

}

void Interpretator::execAddCommand(int time)
{
    assert(time > 0);
    Callable task(boost::bind(&Interpretator::emptyTaskWithDuration, this, time, m_nextTaskId));
    std::stringstream str;
    str << "TaskId : " << m_nextTaskId << std::endl;
    Printer::print(str.str());
    boost::shared_ptr<TaskHandler> taskHandler = m_executor->execute(task);
    m_idToHandler[m_nextTaskId] = taskHandler;
    m_nextTaskId++;
}

void Interpretator::emptyTaskWithDuration(int time, task_id id) {
    boost::this_thread::sleep(boost::posix_time::seconds(time));
    std::stringstream str;
    str << "Task " << id << " completed" << std::endl;
    Printer::print(str.str());
}

void Interpretator::execKillCommand(task_id id)
{
    auto it = m_idToHandler.find(id);
    if (it != m_idToHandler.end()) {
        m_idToHandler[id]->cancel();
        m_idToHandler.erase(it);
        std::stringstream str;
        str << "Task " << id << " killed" << std::endl;
        Printer::print(str.str());
    } else {
        Printer::print("Invalid task id\n");
    }
}

void Printer::print(const std::string &str)
{
    boost::lock_guard<boost::mutex> lock(m_mutex);
    std::cout << str;
}


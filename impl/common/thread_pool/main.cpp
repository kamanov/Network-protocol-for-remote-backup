#include <iostream>
#include <csignal>
#include <boost/program_options.hpp>
#include <boost/bind.hpp>
#include "interpretator.h"
#include <boost/function.hpp>

namespace po = boost::program_options;

bool parseCommandLine(int argc, char* argv[], size_t& hotThreadsNum, size_t& timeout) {
    long long hotNum = 0;
    long long time = 0;
    po::options_description desc("Programm Options");
    desc.add_options()
            ("hotNum", po::value<long long>(&hotNum)->required(), "Number of hot threads in thread pool (>= 0)")
            ("timeout", po::value<long long>(&time)->required(), "Waiting thread lifetime (> 0)");
    po::variables_map vm;
    try {
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);
        if (hotNum < 0 || time <= 0) {
            throw po::error("Invalid programm options");
        }
    }
    catch(po::error& e) {
          std::cerr << "ERROR: " << e.what() << std::endl;
          std::cerr << desc << std::endl;
          return false;
    }
    timeout = (size_t)time;
    hotThreadsNum = (size_t)hotNum;


    return true;
}
static Interpretator intepretator;
void signalHandler(int signum) {
    intepretator.signalHandler(signum);
}

int main(int argc, char* argv[])
{
    size_t hotThreadsNum = 0;
    size_t timeout = 0;
    if (!parseCommandLine(argc, argv, hotThreadsNum, timeout))
        return 1;
    std::signal(SIGINT, &signalHandler);
    std::signal(SIGTERM, &signalHandler);
    intepretator.init(hotThreadsNum, timeout);
    intepretator.run();

    return 0;
}

#include "printer.h"



void Printer::print(std::string &str)
{
    boost::lock_guard<boost::mutex> lock(m_mutex);
    std::cout << str;
}

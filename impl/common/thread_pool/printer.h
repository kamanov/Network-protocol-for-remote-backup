#ifndef PRINTER_H
#define PRINTER_H
#include <boost/thread/thread.hpp>

class Printer
{
public:
    ~Printer();
    void print(std::string& str);
private:
    static boost::mutex m_mutex;
};

#endif // PRINTER_H

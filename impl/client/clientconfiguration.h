#ifndef CLIENTCONFIGURATION_H
#define CLIENTCONFIGURATION_H
#include <string>
#include "libconfig.h++"

class ClientConfiguration
{
public:

    static ClientConfiguration* getInstance();

    struct ServerInfo {
        std::string ip_addr;
        int port;
    };

    ServerInfo serverInfo() { return m_server_info; }

private:
    ClientConfiguration();
    bool init();
    ClientConfiguration(ClientConfiguration const&) = delete;
    void operator=(ClientConfiguration const&) = delete;
    void read_config(libconfig::Config* cfg);

    bool m_is_valid;
    ServerInfo m_server_info;
};

#endif // CLIENTCONFIGURATION_H

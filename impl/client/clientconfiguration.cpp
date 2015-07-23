#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "clientconfiguration.h"

using namespace libconfig;
static const char* k_config_filename = "client.cfg";

static const char* k_server_ip_addr = "client.server.ip_addr";
static const char* k_server_port = "client.server.port";

ClientConfiguration *ClientConfiguration::getInstance()
{
    static ClientConfiguration instance;
    if (!instance.m_is_valid) {
        return nullptr;
    }
    return &instance;
}

ClientConfiguration::ClientConfiguration()
{
    m_is_valid = init();
}

bool ClientConfiguration::init()
{
  Config cfg;

  try
  {
    cfg.readFile(k_config_filename);
  } catch(const FileIOException &fioex) {
    std::cerr << "I/O error while reading file." << std::endl;
    return false;
  } catch(const ParseException &pex) {
    std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
              << " - " << pex.getError() << std::endl;
    return false;
  }

  try
  {
    read_config(&cfg);
  } catch(const SettingNotFoundException &nfex) {
    std::cerr << "Invalid configuration file" << std::endl;
    return false;
  }

  return true;
}

void ClientConfiguration::read_config(Config* cfg)
{
    cfg->lookupValue(k_server_ip_addr, m_server_info.ip_addr);
    cfg->lookupValue(k_server_port, m_server_info.port);
}



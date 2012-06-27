#include "gateway.hpp"

namespace hdfs_httpfs {
  
  gateway::gateway(const std::string& host, unsigned int port, const std::string& user)
    :site_(host, port, user)
  {
  }
  gateway::~gateway(){}

  file_ptr_t gateway::file(const std::string& path)
  {
    return file_ptr_t(new hdfs_httpfs::file(site_, path));
  }

  dir_ptr_t gateway::dir(const std::string& path)
  {
    return dir_ptr_t(new hdfs_httpfs::dir(site_, path));
  }
}

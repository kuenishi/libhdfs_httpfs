#pragma once

#include <string>
#include <pficommon/lang/shared_ptr.h>

#include "file.hpp"
#include "dir.hpp"

namespace hdfs_httpfs {

  typedef pfi::lang::shared_ptr<file> file_ptr_t;
  typedef pfi::lang::shared_ptr<dir>  dir_ptr_t;

  class gateway {
  public:
    gateway(const std::string& host, unsigned int port, const std::string& user);
    ~gateway();

    file_ptr_t file(const std::string& path);
    dir_ptr_t  dir(const std::string& path);

  private:
    httpfs_site site_;
  };

}

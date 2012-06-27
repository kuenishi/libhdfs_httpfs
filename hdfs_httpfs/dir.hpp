#pragma once

#include <vector>

#include "httpfs_site.hpp"

namespace hdfs_httpfs {

  class dir {
  public:
    dir(const httpfs_site& site, const std::string& path);
    ~dir();

    std::vector<std::string> list();
    const std::string& path()const {return path_;}
    
  private:
    std::string path_;
    httpfs_site site_;
  };

}

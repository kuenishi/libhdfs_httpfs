#pragma once

#include <string>
#include <istream>
#include <ostream>
#include "httpfs_site.hpp"

namespace hdfs_httpfs {

  class file {
  public:
    file(const httpfs_site& site, const std::string& path);
    ~file();

    bool exists();
    void create();
    void unlink();

    size_t read(unsigned char* buf, size_t len);
    size_t write(unsigned char* buf, size_t len);

    const std::string& path() const {return path_;}

  private:
    httpfs_site site_;
    std::string path_;
  };

}

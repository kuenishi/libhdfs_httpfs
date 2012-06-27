#include "../hdfs_httpfs.hpp"

#include <string>
#include <stdio.h>

namespace hdfs_httpfs {

  static const unsigned int MAJOR_VERSION = 0;
  static const unsigned int MINOR_VERSION = 0;
  static const unsigned int REVERSION = 1;
  static const std::string LIBNAME = "libhdfs_httpfs";

  std::string name(){
    return LIBNAME;
  }
  std::string version(){
    char buf[16];
    sprintf(buf, "%d.%d.%d", MAJOR_VERSION, MINOR_VERSION, REVERSION);
    return std::string(buf);
  }

}

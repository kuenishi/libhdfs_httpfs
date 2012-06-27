
#include "httpfs_site.hpp"
#include <sstream>

namespace hdfs_httpfs {

  std::string httpfs_site::uri(const std::string& path) const
  {
    std::stringstream ss;
    ss << "http://" << host << ":" << port << "/webhdfs/v1"
       << path << "?user.name=" << user;
    return ss.str();
  }

  pfi::network::uri httpfs_site::uri(const std::string& path,
				     const std::string& op, bool data) const {
    std::stringstream ss;
    ss << "http://" << host << ":" << port
       << "/webhdfs/v1"  << path << "?user.name=" << user << "&op=" << op;

    if(data) ss << "&data=true";

    return pfi::network::uri(ss.str());

  }

}

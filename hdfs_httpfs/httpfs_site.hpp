#pragma once

#include <string>
#include <pficommon/network/http.h>

namespace hdfs_httpfs {

  // HTTP methods
  static const std::string GET = "GET";
  static const std::string POST = "POST";
  static const std::string PUT = "PUT";
  static const std::string DELETE = "DELETE";

  static const std::string GETFILESTATUS = "GETFILESTATUS";
  static const std::string LISTSTATUS = "LISTSTATUS";
  static const std::string CREATE = "CREATE";
  static const std::string OPEN = "OPEN";
  static const std::string APPEND = "APPEND";

  struct httpfs_site {
    httpfs_site(const std::string& host, unsigned int port, const std::string& user)
      :host(host),port(port),user(user){}
    std::string host;
    unsigned int port;
    std::string user;

    std::string uri(const std::string& path) const ;
    pfi::network::uri uri(const std::string& path, const std::string& op,
			  bool data = false) const ;
  };

}

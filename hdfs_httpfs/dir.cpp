
#include "dir.hpp"
#include <pficommon/text/json.h>

using pfi::text::json::json;
using pfi::text::json::json_cast;
using pfi::text::json::from_json;

namespace hdfs_httpfs {
  
  dir::dir(const httpfs_site& site, const std::string& path)
    : path_(path), site_(site)
  {}
  dir::~dir(){}
  
  std::vector<std::string> dir::list()
  {
    pfi::network::http::request req(GET, site_.uri(path_, LISTSTATUS));
    req.head()["Host"] = site_.host;
    
    pfi::lang::shared_ptr<pfi::network::stream_socket> ss(new pfi::network::stream_socket());
    ss->connect(site_.host, site_.port);
    
    req.send(ss);
    pfi::network::http::response res(ss);
    
    json js;
    res.body() >> js;

    std::vector<std::string> ret;

    //std::cout << js;
    for(size_t s = 0; s < js["FileStatuses"]["FileStatus"].size() ; ++s){
      std::string tmp;
      from_json<std::string>(js["FileStatuses"]["FileStatus"][s]["pathSuffix"], tmp);
      ret.push_back(tmp);
    }
    return ret;
  }
}

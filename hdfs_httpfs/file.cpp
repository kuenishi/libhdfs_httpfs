
#include "file.hpp"
#include <pficommon/text/json.h>

using namespace pfi::text::json;

namespace hdfs_httpfs {

  file::file(const httpfs_site& site, const std::string& path)
    :site_(site), path_(path){}
  file::~file(){}

  bool file::exists()
  {
    pfi::network::http::request req(GET, site_.uri(path_, GETFILESTATUS));
    req.head()["Host"] = site_.host;
    
    pfi::lang::shared_ptr<pfi::network::stream_socket> ss(new pfi::network::stream_socket());
    ss->connect(site_.host, site_.port);
    
    req.send(ss);
    pfi::network::http::response res(ss);

    // json js;
    // res.body() >> js;
    // std::cout << pretty(js) << std::endl;

    return res.code() == 200;
  }
  void file::create(){
    std::cout  << site_.uri(path_, CREATE, true) << std::endl;
    pfi::network::http::request req(PUT, site_.uri(path_, CREATE, true));
    req.head()["Host"] = site_.host;

    req.head()["Content-Length"] = "4";
    req.head()["Content-Type"] = "application/octet-stream";
    req.body() << "aaaa";
    
    pfi::lang::shared_ptr<pfi::network::stream_socket> ss(new pfi::network::stream_socket());
    ss->connect(site_.host, site_.port);
    req.send(ss);
    pfi::network::http::response res(ss);

    if(res.code() == 201){
      std::cout << __func__ << ": ok" << std::endl;
    }else if(res.code() / 200 == 0){
      std::cout << __func__ << ": ok -> " << res.code() << std::endl;
    }else{
      std::cout << __func__ << ": ng -> " << res.code() << std::endl;
    }

  }

  void file::unlink(){
    pfi::network::http::request req(DELETE, site_.uri(path_, DELETE));
    req.head()["Host"] = site_.host;
    
    pfi::lang::shared_ptr<pfi::network::stream_socket> ss(new pfi::network::stream_socket());
    ss->connect(site_.host, site_.port);
    
    req.send(ss);
    pfi::network::http::response res(ss);

    if(res.code() == 200){ // and (json_cast<std::string>(js["boolean"]) == "true") ){
      std::cout << __func__ << ": ok" << std::endl;
    }else{
      json js;
      res.body() >> js;
      std::cout << pretty(js) << std::endl;
    }

  }

  size_t file::read(unsigned char* buf, size_t len){
    pfi::network::http::request req(GET, site_.uri(path_, OPEN));
    req.head()["Host"] = site_.host;
    
    pfi::lang::shared_ptr<pfi::network::stream_socket> ss(new pfi::network::stream_socket());
    ss->connect(site_.host, site_.port);
    
    req.send(ss);
    pfi::network::http::response res(ss);

    if(res.code() == 200){ // and (json_cast<std::string>(js["boolean"]) == "true") ){
      res.body() >> buf;
      std::cout << __func__ << ": ok" << std::endl;
      size_t s = pfi::lang::lexical_cast<size_t>(res.head()["Content-Length"]);
      return s;
    }else{
      json js;
      res.body() >> js;
      std::cout << pretty(js) << std::endl;
    }
    return 0;

  }
  size_t file::write(unsigned char* buf, size_t len){
    pfi::network::http::request req(POST, site_.uri(path_, APPEND, true));
    req.head()["Host"] = site_.host;
    req.head()["Content-Length"] = pfi::lang::lexical_cast<std::string>(len);
    req.head()["Content-Type"] = "application/octet-stream";
    req.body() << buf;
    
    pfi::lang::shared_ptr<pfi::network::stream_socket> ss(new pfi::network::stream_socket());
    ss->connect(site_.host, site_.port);
    
    req.send(ss);
    pfi::network::http::response res(ss);

    if(res.code() == 200){ // and (json_cast<std::string>(js["boolean"]) == "true") ){
      std::cout << __func__ << ": ok" << std::endl;
      return len;
    }else{
      json js;
      res.body() >> js;
      std::cout << pretty(js) << std::endl;
    }
    return 0;
  }

}

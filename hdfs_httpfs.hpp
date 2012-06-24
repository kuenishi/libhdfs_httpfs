#pragma once

#include <istream>
#include <ostream>

namespace httpfs {

int version();

class ifstream : public std::istream {
public:
  ifstream(const char*);
  virtual ~ifstream();

  template <typename T>
  std::istream& operator >> (const T& t){
    return this;
  }
};


class ofstream : public std::ostream {
  ofstream(const char*);
  virtual ~ofstream();

  template <typename T>
  std::ostream& operator << (const T& t){
    return this;
  }

};

}

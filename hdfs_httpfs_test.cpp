#include <iostream>
#include "hdfs_httpfs.hpp"
using namespace std;


int main(){

  cout << hdfs_httpfs::name() << " " << hdfs_httpfs::version() << endl;

  hdfs_httpfs::gateway gw("127.0.0.1", 14000, "kuenishi");
  hdfs_httpfs::dir_ptr_t d = gw.dir("/");
  
  vector<string> l = d->list();
  for(size_t s=0; s<l.size(); ++s){
    cout << l[s] << endl;
  }

  hdfs_httpfs::file_ptr_t f = gw.file("/hoge.txt");
  
  if(f->exists()){
    cout << f->path() << " exists" << endl;
    cout << "unlink===" << endl;
    f->unlink();
  }

  cout << "create===" << endl;
  f->create();
  cout << "1==" << f->exists() << endl;

  {
    cout << "append===" << endl;
    unsigned char buf0[] = "deadbeef";
    size_t s = f->write(buf0, 8);
    cout << s << endl;
    cout << "read===" << endl;
    unsigned char buf[1024];
    s = f->read(buf, 1024);
    cout << s << endl;
    buf[s] = '\0';
    cout << buf << endl;
  }
    
  // hdfs_httpfs::ifstream ifs("http://127.0.0.1:14000/webhdfs/v1/?user.name=kuenishi&op=LISTSTATUS");
  // ifs.send();
  // // string line;
  // // while(ifs >> line){
  // //    cout << line << endl;
  // //  }
  // }
  return 0;
}

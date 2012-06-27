#pragma once

#include <string>

#include "hdfs_httpfs/gateway.hpp"

namespace hdfs_httpfs {

  std::string name();
  std::string version();

// class ifstream : public std::istream {
// public:
//   ifstream(const char*);
//   virtual ~ifstream();

//   template <typename T>
//   std::istream& operator >> (const T& t){
//     return this;
//   }
//   void send();

// private:
//   pfi::network::http::request req;
// };

// // static const unsinged int create =   0x0001;
// // static const unsinged int truncate = 0x0002;

// class ofstream : public std::ostream {
// public:
//   ofstream(const char*, unsigned int);
//   virtual ~ofstream();

//   template <typename T>
//   std::ostream& operator << (const T& t){
//     // run append here
//     return this;
//   }

// };


}

//Operations
//HTTP GET
// OPEN (see FileSystem.open)
// GETFILESTATUS (see FileSystem.getFileStatus)
// LISTSTATUS (see FileSystem.listStatus)
// GETCONTENTSUMMARY (see FileSystem.getContentSummary)
// GETFILECHECKSUM (see FileSystem.getFileChecksum)
// GETHOMEDIRECTORY (see FileSystem.getHomeDirectory)
// GETDELEGATIONTOKEN (see FileSystem.getDelegationToken)
// GETDELEGATIONTOKENS (see FileSystem.getDelegationTokens)
//HTTP PUT
// CREATE (see FileSystem.create)
// MKDIRS (see FileSystem.mkdirs)
// CREATESYMLINK (see FileContext.createSymlink)
// RENAME (see FileSystem.rename)
// SETREPLICATION (see FileSystem.setReplication)
// SETOWNER (see FileSystem.setOwner)
// SETPERMISSION (see FileSystem.setPermission)
// SETTIMES (see FileSystem.setTimes)
// RENEWDELEGATIONTOKEN (see FileSystem.renewDelegationToken)
// CANCELDELEGATIONTOKEN (see FileSystem.cancelDelegationToken)
//HTTP POST
// APPEND (see FileSystem.append)
//HTTP DELETE
// DELETE (see FileSystem.delete)

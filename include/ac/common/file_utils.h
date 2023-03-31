#pragma once
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <unistd.h>

namespace ac {
namespace common {
namespace file {
inline bool exists (const std::string& name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}


} // namespace file
} // namespace common
} // namespace ac

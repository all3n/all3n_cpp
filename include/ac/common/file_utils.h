#pragma once
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <unistd.h>

namespace ac {
namespace common {
namespace file {
inline bool exists(const std::string &name) {
  std::ifstream f(name.c_str());
  return f.good();
}
} // namespace file
} // namespace common
} // namespace ac

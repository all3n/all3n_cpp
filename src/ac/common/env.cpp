#include "ac/common/env.h"
#include <cstdlib>

namespace ac{namespace common {

std::string get_env(const std::string &key, const std::string & def){
  const char * var = getenv(key.c_str());
  return var ? var : def;
}

}}

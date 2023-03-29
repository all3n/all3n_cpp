#include "ac/common/string_utils.h"
#include <sstream>

namespace ac {
namespace common {
namespace string {

void split(const std::string &line, const std::string &delimiter,
           std::vector<std::string> &out) {
  size_t pos_start = 0, pos_end, delim_len = delimiter.length();
  std::string token;

  while ((pos_end = line.find(delimiter, pos_start)) != std::string::npos) {
    token = line.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    out.push_back(token);
  }
  out.push_back(line.substr(pos_start));
}

void split(const std::string &line, char delimiter,
           std::vector<std::string> &out) {
  std::stringstream ss(line);
  std::string item;

  while (getline(ss, item, delimiter)) {
    out.push_back(item);
  }
}

} // namespace string
} // namespace common
} // namespace ac

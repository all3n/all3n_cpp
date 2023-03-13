#include "ac/common/datetime.h"
#include <cstring>
namespace ac {
namespace common {

std::string DateTime::toString(const std::string &format) const {
  std::ostringstream oss;
  struct tm t;
  t.tm_year = year - 1900;
  t.tm_mon = month - 1;
  t.tm_mday = day;
  t.tm_hour = hour;
  t.tm_min = minute;
  t.tm_sec = second;
  char buf[100];
  if (strftime(buf, sizeof(buf), format.c_str(), &t) == 0) {
    return "";
  }
  return buf;

  return "";
}

DateTime DateTime::parse(const std::string &str, const std::string &format) {
  DateTime dt;
  struct tm t = {};
  std::memset(&t, 0, sizeof(t));
  if (strptime(str.c_str(), format.c_str(), &t) == nullptr) {
    return dt;
  }
  dt.year = t.tm_year + 1900;
  dt.month = t.tm_mon + 1;
  dt.day = t.tm_mday;
  dt.hour = t.tm_hour;
  dt.minute = t.tm_min;
  dt.second = t.tm_sec;
  return dt;
}
time_t DateTime::getTimestamp() const {
  struct tm t;
  t.tm_year = year - 1900;
  t.tm_mon = month - 1;
  t.tm_mday = day;
  t.tm_hour = hour;
  t.tm_min = minute;
  t.tm_sec = second;
  t.tm_isdst = -1;
  return mktime(&t);
}

} // namespace common
} // namespace ac

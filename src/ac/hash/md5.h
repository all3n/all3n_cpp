#pragma once
#include <string>
#if __cplusplus >= 201703L
#include <string_view>
#endif // __cplusplus >= 201703L

namespace ac {
namespace hash {
void md5(const unsigned char *key, unsigned int length, unsigned char *result);
std::string md5(const std::string &s);
} // namespace hash
} // namespace ac

#pragma once
#include <string>
namespace ac {
namespace hash {

void MurmurHash3_x86_32(const void *key, int len, uint32_t seed, void *out);
void MurmurHash3_x86_128(const void *key, const int len, uint32_t seed,
                         void *out);
int32_t MurmurHash32(const std::string &str);
int32_t MurmurHash32(const std::string &str, uint32_t seed);
int64_t MurmurHash64(const std::string &str);
int64_t MurmurHash64(const std::string &str, uint32_t seed);

} // namespace hash
} // namespace ac

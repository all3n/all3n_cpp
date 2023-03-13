#pragma once
#include <cstdio>
#include <string>
#include <vector>

namespace ac {
namespace common {
namespace string {
/**
 * split string by string
 * line[in] : input string
 * delimiter[in]: delimiter string to split
 * out[out]: output vector string
 */
void split(const std::string &line, const std::string &delimiter,
           std::vector<std::string> &out);
/**
 * split string by char
 * line[in] : input string
 * delimiter[in]: delimiter string to split
 * out[out]: output vector string
 */
void split(const std::string &line, char delimiter,
           std::vector<std::string> &out);

} // namespace string
} // namespace common
} // namespace ac

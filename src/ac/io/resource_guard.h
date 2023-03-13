#pragma once
#include <cstdio>
#include <iostream>
#include <memory>
#include <sys/socket.h>
#include <unistd.h>

namespace ac {
namespace io {
template <typename ResourceType, typename DeleterType> class resource_guard {
public:
  resource_guard(ResourceType resource, DeleterType deleter)
      : resource_(resource), deleter_(deleter) {}

  ~resource_guard() {
    if (resource_)
      deleter_(resource_);
  }

private:
  ResourceType resource_;
  DeleterType deleter_;
};

void socket_deleter(int fd);
void file_deleter(std::FILE *file);
using socket_guard = resource_guard<int, decltype(&socket_deleter)>;
using file_guard = resource_guard<std::FILE *, decltype(&file_deleter)>;
#define SOCKET_GUARD(s) resource_guard<int, decltype(&socket_deleter)>(s, socket_deleter);
#define FILE_GUARD(s) resource_guard<std::FILE *, decltype(&file_deleter)>(s, file_deleter);


} // namespace io
} // namespace ac

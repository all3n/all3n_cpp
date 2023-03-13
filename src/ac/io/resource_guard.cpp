#include "ac/io/resource_guard.h"

namespace ac {
namespace io {

void socket_deleter(int fd) { ::close(fd); }
void file_deleter(std::FILE *file) { std::fclose(file); }

} // namespace io
} // namespace ac

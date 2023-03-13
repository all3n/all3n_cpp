#include <gtest/gtest.h>
#include <ac/io/resource_guard.h>

using namespace ac::io;
TEST(AcIoTestFileGuard, BasicAssertions) {
  std::FILE * f = fopen("/tmp/a.txt", "rw");
  FILE_GUARD(f);
}

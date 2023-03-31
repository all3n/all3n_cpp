#include <ac/common/string_utils.h>
#include <gtest/gtest.h>

using namespace ac::common::string;
TEST(AcCommonStringUtils, BasicAssertions) {
  std::string line = "a,b,c";
  std::vector<std::string> out;
  Split(line, ",", out);
  EXPECT_EQ(out.size(), 3);
  EXPECT_EQ(out[0], "a");

  int a = 10;
  double b = 3.14;
  std::string c = "hello";
}

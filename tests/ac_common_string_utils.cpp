#include <gtest/gtest.h>
#include <ac/common/string_utils.h>

using namespace ac::common::string;
TEST(AcCommonStringUtils, BasicAssertions) {
  std::string line = "a,b,c";
  std::vector<std::string> out;
  split(line, ",", out);
  EXPECT_EQ(out.size(), 3);
  EXPECT_EQ(out[0], "a");
  std::vector<std::string> out2;
  split(line, ',', out2);
  EXPECT_EQ(out2.size(), 3);
  EXPECT_EQ(out2[0], "a");
}

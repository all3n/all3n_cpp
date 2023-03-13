#include <gtest/gtest.h>
#include <ac/common/datetime.h>

using namespace ac::common;
TEST(AcCommonDateTime, BasicAssertions) {
  DateTime dt = DateTime::parse("2023-01-01", DATE_FORMAT);
  std::cout << dt.toString() << std::endl;
  DateTime now;
  std::cout << now.toString() << std::endl;
  
  DateTime dt3 = DateTime::parse("2023-01-01 01:00:00", DATETIME_FORMAT);
  std::cout << dt3.toString() << std::endl;
  std::cout << dt3.getTimestamp() << std::endl;


}

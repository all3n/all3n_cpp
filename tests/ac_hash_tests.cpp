#include <gtest/gtest.h>
#include <ac/hash/murmurhash3.h>
#include <ac/hash/base64.h>
#include <ac/hash/md5.h>

using namespace ac::hash;
TEST(AcHashMurmurHash, BasicAssertions) {
  std::string x = "test_64";
  int64_t hash64 = MurmurHash64(x, x.length());
  ASSERT_EQ(hash64, -7848302612998542228);
  int64_t hash642 = MurmurHash64(x);
  ASSERT_EQ(hash642, -7798803116569785951);
}


TEST(AcHashBase64, BasicAssertions) {
  std::string x = "test_64";
  std::string out = base64_encode(x);
  ASSERT_EQ(out, "dGVzdF82NA==");
}
TEST(AcHashMd5, BasicAssertions) {
  std::string x = "admin";
  std::string out = md5(x);
  std::cout << out<< std::endl;
}

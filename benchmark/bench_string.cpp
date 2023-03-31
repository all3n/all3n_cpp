#include "bench_string.h"
void BM_StringSplit(benchmark::State &state){
  std::vector<std::string> out;
  for(auto _: state){
    ac::common::string::Split("test:asf", ":", out);
  }
}

void BM_StringSplitByChar(benchmark::State &state){
  std::vector<std::string> out;
  for(auto _: state){
  }
}

BENCHMARK(BM_StringSplit);
BENCHMARK(BM_StringSplitByChar);

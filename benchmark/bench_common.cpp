#include "bench_common.h"
void BM_file_exists(benchmark::State &state){
  for(auto _: state){
    ac::common::file::exists("/dev/null");
  }
}

BENCHMARK(BM_file_exists);

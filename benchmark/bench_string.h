#pragma once
#include <benchmark/benchmark.h>
#include <ac/common/string_utils.h>

void BM_StringSplit(benchmark::State &state);
void BM_StringConcat(benchmark::State &state);

cmake_minimum_required(VERSION 3.0)
project(ac VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(BUILD_GMOCK OFF CACHE BOOL "")
set(BUILD_GTEST OFF CACHE BOOL "")
set(INSTALL_GTEST OFF)

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h")
file(GLOB_RECURSE TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp")
message(STATUS "sources:${SOURCES}")
message(STATUS "headers:${HEADERS}")
message(STATUS "test sources:${TEST_SOURCES}")

add_library(${PROJECT_NAME} ${SOURCES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
  #install(FILES ${HEADERS} DESTINATION include)

#
install(DIRECTORY include/
    DESTINATION include
)

find_package(GTest)

enable_testing()
add_executable(
  ac_tests
  ${TEST_SOURCES}
)

include(GoogleTest)
target_link_libraries(ac_tests ${PROJECT_NAME} GTest::gtest_main)
gtest_discover_tests(ac_tests)

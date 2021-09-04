# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(cryptography LANGUAGES CXX)



# set(COMMON_SOURCES file1.cpp file2.cpp)
# set(TARGET_SOURCES main.cpp)
# set(TEST_SOURCES  run_tests.cpp test_file1.cpp test_file2.cpp)
# add_executable(application ${COMMON_SOURCES} ${TARGET_SOURCES})
# add_executable(tests ${COMMON_SOURCES} ${TEST_SOURCES})

set(CRYPTOGRAPHY_SOURCES cipher/atbash/main.cpp cipher/atbash/atbash.cpp)
set(CRYPTANALYSIS_SOURCES cryptanalysis/main.cpp cryptanalysis/message.cpp)

add_executable(atbash ${CRYPTOGRAPHY_SOURCES})
add_executable(cryptanalsys ${CRYPTANALYSIS_SOURCES})
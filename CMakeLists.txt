# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(cryptography LANGUAGES CXX)

add_executable(atbash cipher/atbash/main.cpp cipher/atbash/atbash.cpp)

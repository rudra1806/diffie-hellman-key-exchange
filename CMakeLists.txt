cmake_minimum_required(VERSION 3.10)
project(DiffieHellmanCpp)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(DiffieKeyExchange src/main.cpp src/diffie_hellman.cpp)
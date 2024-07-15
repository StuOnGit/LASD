cmake_minimum_required(VERSION 3.13)
project(Lasd_es1)
set(CMAKE_CXX_STANDARD 14)
include_directories(container list vector zlasdtest zmytest)
add_executable(main
        zlasdtest/exercise1/fulltest.cpp
        zlasdtest/exercise1/simpletest.cpp
        zlasdtest/container/container.cpp
        zlasdtest/test.cpp
        zmytest/test.cpp
        main.cpp)
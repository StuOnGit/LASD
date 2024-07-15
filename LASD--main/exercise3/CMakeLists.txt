cmake_minimum_required(VERSION 3.13)
project(Lasd_es3)
set(CMAKE_CXX_STANDARD 14)
include_directories(binarytree container iterator list queue vector zlasdtest zmytest)
add_executable(main
        zlasdtest/exercise1/fulltest.cpp
        zlasdtest/exercise1/simpletest.cpp
        zlasdtest/test.cpp
        zlasdtest/container/container.cpp
        zlasdtest/exercise2/fulltest.cpp
        zlasdtest/exercise2/simpletest.cpp
        zlasdtest/exercise3/fulltest.cpp
        zlasdtest/exercise3/simpletest.cpp
        zmytest/test.cpp
        main.cpp)
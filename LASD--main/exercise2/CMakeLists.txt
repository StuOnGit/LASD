cmake_minimum_required(VERSION 3.19)
project(exercise2)
include_directories(container list queue vector zlasdtest zmytest stack queue/vec)
add_executable(main
        zlasdtest/exercise2/fulltest.cpp
        zlasdtest/exercise2/simpletest.cpp
        zlasdtest/container/container.cpp
        zlasdtest/test.cpp
        zmytest/test.cpp
        main.cpp
        )

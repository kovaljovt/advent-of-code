cmake_minimum_required(VERSION 3.25)
project(advent)

set(CMAKE_CXX_STANDARD 17)

add_executable(2015_01 2015/Day01/Day01.cpp
        2015/Day04/Day04.txt.cpp
)
add_executable(2015_02 2015/Day02/Day02.cpp)
add_executable(2015_03 2015/Day03/Day03.cpp)
add_executable(2015_04 2015/Day04/Day04.txt.cpp)
add_executable(2015_09 2015/Day09/main.cpp 2015/Day09/Day09.h 2015/Day09/Day09.cpp)

add_executable(2016_01 2016/Day01/Day01.cpp)
add_executable(2016_02 2016/Day02/Day02.cpp)
add_executable(2016_03 2016/Day03/Day03.cpp)

add_executable(2017_01 2017/Day01/Day01.cpp)
add_executable(2017_02 2017/Day02/Day02.cpp)

add_executable(2018_01 2018/Day01/Day01.cpp)
add_executable(2018_02 2018/Day02/Day02.cpp)

add_executable(2019_01 2019/Day01/Day01.cpp)
add_executable(2019_02 2019/Day02/Day02.cpp)

add_executable(2020_01 2020/Day01/Day01.cpp)
add_executable(2020_02 2020/Day02/Day02.cpp)
add_executable(2020_03 2020/Day03/Day03.cpp)
add_executable(2020_06 2020/Day06/Day06.cpp)

add_executable(2021_01 2021/Day01/Day01.cpp)
add_executable(2021_02 2021/Day02/Day02.cpp)
add_executable(2021_03 2021/Day03/Day03.cpp)

add_executable(2022_01 2022/Day01/Day01.cpp)
add_executable(2022_02 2022/Day02/Day02.cpp)
add_executable(2022_03 2022/Day03/Day03.cpp)
add_executable(2022_04 2022/Day04/Day04.cpp)
add_executable(2022_06 2022/Day06/Day06.cpp)
add_executable(2022_12 2022/Day12/main.cpp 2022/Day12/Day12.cpp 2022/Day12/Day12.h)
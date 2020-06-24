cmake_minimum_required(VERSION 3.16)
project(common_graphs)

set(CMAKE_CXX_STANDARD 20)

add_executable(common_graphs main.cpp classes.h EdgeList.cpp EdgeList.h AdjMatrix.cpp AdjMatrix.h IncMatrix.cpp IncMatrix.h AdjStruct.cpp AdjStruct.h)
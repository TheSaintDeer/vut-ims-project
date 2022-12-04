cmake_minimum_required(VERSION 3.23)
project(ims_project)

set(CMAKE_CXX_STANDARD 14)

#find_package(Python3 COMPONENTS Development NumPy)
#find_package(cxxplot REQUIRED)
#target_link_libraries(ims_project PRIVATE cxxplot::cxxplot Python3::Python Python3::NumPy)
#link_libraries(cxxplot::cxxplot)
#link_libraries(Python3::Python)
#link_libraries(Python3::NumPy)

add_executable(ims_project main.cpp PointN.cpp PointN.h NystromN.cpp NystromN.h FlyingBall.cpp FlyingBall.h Wind.cpp Wind.h Test.cpp Test.h)

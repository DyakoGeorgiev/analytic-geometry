cmake_minimum_required(VERSION 3.13)
project(ProjectLinearAlgebra)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProjectLinearAlgebra main.cpp model/Point.h exceptions/EqualPointException.h exceptions/EqualPointException.cpp model/Point.cpp model/Vector.cpp model/Vector.h exceptions/VectorLengthException.cpp exceptions/VectorLengthException.h model/Line.cpp model/Line.h model/Triangle.cpp model/Triangle.h ui/PointMenu.cpp ui/PointMenu.h ui/Menu.h ui/DefaultMenu.cpp ui/DefaultMenu.h ui/VectorMenu.cpp ui/VectorMenu.h ui/OperationsMenu.h ui/StringsMenu.cpp ui/StringsMenu.h)
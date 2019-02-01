cmake_minimum_required(VERSION 3.13)
project(ProjectLinearAlgebra)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProjectLinearAlgebra src/main.cpp src/model/Point.h src/exceptions/EqualPointException.h src/exceptions/EqualPointException.cpp src/model/Point.cpp src/model/Vector.cpp src/model/Vector.h src/exceptions/VectorLengthException.cpp src/exceptions/VectorLengthException.h src/model/Line.cpp src/model/Line.h src/model/Triangle.cpp src/model/Triangle.h src/ui/PointMenu.cpp src/ui/PointMenu.h src/ui/Menu.h src/ui/DefaultMenu.cpp src/ui/DefaultMenu.h src/ui/VectorMenu.cpp src/ui/VectorMenu.h src/ui/OperationsMenu.h src/ui/StringsMenu.cpp src/ui/StringsMenu.h)
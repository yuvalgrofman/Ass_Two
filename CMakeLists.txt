
cmake_minimum_required(VERSION 3.16)
project(Ass_Two)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(AssTwo.out
        classifier/distances/chebyshevDistance.cpp
        classifier/distances/chebyshevDistance.h
        classifier/dataspace/dataSpace.cpp
        classifier/dataspace/dataSpace.h
        classifier/dataspace/dataSpaceCreator.cpp
        classifier/dataspace/dataSpaceCreator.h
        classifier/distances/distance.h
        classifier/distances/euclideanDistance.cpp
        classifier/distances/euclideanDistance.h
        classifier/flower/flower.cpp
        classifier/flower/flower.h
        classifier/flower/flowerPoint.cpp
        classifier/flower/flowerPoint.h
        classifier/flower/flowerReader.cpp
        classifier/flower/flowerReader.h
        classifier/flower/flowerType.h
        classifier/flower/flowerType.cpp
        classifier/distances/manhattanDistance.cpp
        classifier/distances/manhattanDistance.h
        classifier/classifier.cpp
        classifier/classifier.h
        classifier/flower/flowerSorter.h
        classifier/flower/flowerSorter.cpp
        server/server.h server/server.cpp
        main.cpp server/server_handler.cpp server/server_handler.h)
cmake_minimum_required(VERSION 3.17)
project(22s-pa01-kate)

set(CMAKE_CXX_STANDARD 14)

set (input01 "data/100-paintings.txt")
foreach(file IN LISTS input01)
    configure_file(${file} ${file} COPYONLY)
endforeach()

#configure_file(data/4-paintings.txt data/4-paintings.txt COPYONLY)
#configure_file(data/10-paintings.txt data/10-paintings.txt COPYONLY)
#configure_file(data/20-paintings.txt data/20-paintings.txt COPYONLY)
#configure_file(data/50-paintings.txt data/50-paintings.txt COPYONLY)
#configure_file(data/100-paintings.txt data/100-paintings.txt COPYONLY)


add_executable(22s-pa01-kate src/main.cpp src/Paintings.cpp src/Paintings.h src/BruteForce.cpp src/BruteForce.h src/PriciestFirst.cpp src/PriciestFirst.h src/MyOptimization.cpp src/MyOptimization.h src/Parsing.cpp src/Parsing.h)
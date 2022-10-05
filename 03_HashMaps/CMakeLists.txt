cmake_minimum_required(VERSION 3.21)
project(03_HashMaps)

set(CMAKE_CXX_STANDARD 14)

add_executable(03_HashMaps
        src/examples/Dynamic/DynamicArray.cpp
        src/examples/Dynamic/HashMap.cpp
        src/examples/HashFunctions/NamesHash.cpp
        src/examples/HashFunctions/PhonesHash.cpp
        src/homework/HashFunctions/HashFunctions.cpp
        src/homework/HashMapsAreFast/HashMapsAreFast.cpp
        src/homework/VeryDynamic/DynamicHashMap.cpp
        src/homework/VeryDynamic/VeryDynamicArray.cpp
        )
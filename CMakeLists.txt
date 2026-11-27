cmake_minimum_required(VERSION 3.15...3.31)

project(Alekhine-Engine
  VERSION 1.0
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Release)
endif()

add_library(alekhine_core)
target_sources(alekhine_core PRIVATE
  src/board.cpp
  src/piece.cpp) #add all .cpp files here for compilation

target_include_directories(alekhine_core PUBLIC src)
target_compile_options(alekhine_core PRIVATE -Wall -Wextra -Wpedantic)

add_executable(Alekhine-Engine src/main.cpp)
target_link_libraries(Alekhine-Engine PRIVATE alekhine_core)


#cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
#cmake --build build -j$(nproc)
#./build/Alekhine-Engine -H runtime/history.txt -m runtime/move.txt

# Sandbox for quick tests: ./build/sandbox  ->  writes runtime/test.txt
add_executable(sandbox tests/sandbox.cpp)
target_link_libraries(sandbox PRIVATE alekhine_core)

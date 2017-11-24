cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)
include(cmake/HunterGate.cmake)
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.19.52.tar.gz"
    SHA1 "6d3a8135ba62726d810fd8c8c7d97980fa6c3b4a"
)
project(download-nlohmann-json)
hunter_add_package(nlohmann_json)
find_package(nlohmann_json CONFIG REQUIRED)
add_executable(pack ${CMAKE_CURRENT_SOURCE_DIR}/sources/pack.cpp)
add_executable(unpack ${CMAKE_CURRENT_SOURCE_DIR}/sources/unpack.cpp)
target_link_libraries(pack nlohmann_json)
target_link_libraries(unpack nlohmann_json)

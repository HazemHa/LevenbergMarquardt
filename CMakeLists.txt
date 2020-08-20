############

 
cmake_minimum_required(VERSION 3.1)

#name of project in directory
get_filename_component(ProjectId ${CMAKE_CURRENT_LIST_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId})

#SET(CMAKE_BUILD_TYPE Release)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS ON)

 #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=gnu++11 ")
#set bin dir to compile
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories( ${PROJECT_SOURCE_DIR}/include)


file (GLOB_RECURSE SRC_LIST src/*.cpp src/*.c   src/*.h  src/*.hpp)



#find_package (Eigen3 3.3 REQUIRED NO_MODULE)



add_executable(${PROJECT_NAME} ${SRC_LIST})
#target_link_libraries(${PROJECT_NAME} PRIVATE m Eigen3::Eigen)
#target_link_libraries(${PROJECT_NAME} PRIVATE pthread)
target_link_libraries(${PROJECT_NAME} PRIVATE m)

 

cmake_minimum_required (VERSION 3.9 FATAL_ERROR)

set (CMAKE_CXX_STANDARD 11)
set (CXX_STANDARD_REQUIRED)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

#get paths for conan libraries 
conan_set_find_paths()

#use find package to bring in your dependancy.
find_package(GTEST REQUIRED)

#set up where we want our exe to land.
set(PROJECT_BINARY_DIR ./build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/.)

#get all the cpp files in the project
#i know this is supposed to be explict anc glob is bad but meh.
file (GLOB APP_FILES ./*.cpp)

#get all the tests
file( GLOB TESTFILES ../tests/*.cpp )

#We need to swap out the main in the test build as gtest defines a main so remove it from the list.
set (main ${CMAKE_CURRENT_SOURCE_DIR}/./main.cpp)
list(REMOVE_ITEM APP_FILES ${main})

#target for the the program
add_executable(app main.cpp ${APP_FILES})
target_link_libraries(app)

#target for the the program with debug symbols
add_executable(app-debug main.cpp ${APP_FILES})
target_link_libraries(app-debug)
target_compile_options(app-debug PRIVATE -g)

#target for the tests
add_executable(tests ${TESTFILES} ${APP_FILES} )

#enable coverage for the test target
target_link_libraries(tests  GTest::GTest GTest::Main --coverage)
target_compile_options(tests PRIVATE -g -O0 --coverage)

#force cmake to create the gcov files with the correct names.
set ( CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)














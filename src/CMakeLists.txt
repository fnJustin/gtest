cmake_minimum_required (VERSION 3.9 FATAL_ERROR)

set (CMAKE_CXX_STANDARD 11)
set (CXX_STANDARD_REQUIRED)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

#conan style
conan_basic_setup(TARGETS KEEP_RPATHS)

set(PROJECT_BINARY_DIR ./build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/.)

#get all the filesin the project
file (GLOB APP_FILES ./*.cpp)

#get all the tests
file( GLOB TESTFILES ../tests/*.cpp )

#ok we need to swap out the main in the test build.
set (main ${CMAKE_CURRENT_SOURCE_DIR}/./main.cpp)
list(REMOVE_ITEM APP_FILES ${main})

#terget for the the program
add_executable(app main.cpp ${APP_FILES})
target_link_libraries(app)

#target for the tests
add_executable(tests ${TESTFILES} ${APP_FILES} )

#enable coverage for the test target
target_link_libraries(tests  ${CONAN_TARGETS} --coverage)
target_compile_options(tests PRIVATE -g -O0 --coverage)

#force cmake to create the gcov files with the correct names.
set ( CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)














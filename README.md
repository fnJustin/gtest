# C++ sonarqube cmake gtest gcov valgrind example
Simple example of using gtest for unit test and gcov coverage stats.
You can use any testing framework, e.g. catch in the same way.

NB, i am using conanio to source the gtest dependancy from the bincrafters repo. 
[https://api.bintray.com/conan/bincrafters/public-conan]

> mkdir build

> cd build

> conan install ../src

> cmake ../src

> make

or

> make app

or

> make tests

## This spits out 3 executables
app - the application
app-debug - the application with debug symbols
tests - the appliaction unit tests

# To get coverage metrics on osx or linux from the build folder

> ./tests

> gcov ../src/*.cpp --object-directory CMakeFiles/tests.dir/

## To get nicer html format

>gcovr -r ../src --object-directory ./CMakeFiles/tests.dir/ --html --html-details -o output.html

# Sonarqube (output all the test info to files and upload)

gtest> cd /build

gtest/build> ./tests

gtest/build> gcov ../src/*.cpp --object-directory CMakeFiles/tests.dir/

gtest/build> cd ..

gtest> gcovr -r . -x --object-directory=build >coverage.xml

gtest> valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --xml=yes --xml-file=valgrind.xml build/app-debug

gtest> cppcheck --xml --xml-version=2 --enable=all 2>cppcheck.xml ./src

gtest> sonar-scanner



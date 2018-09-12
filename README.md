Simple example of using the catch library and gtest for unit test and gcov coverage stats.
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

This spits out 2 executables
app - the application
tests - the appliaction unit tests

To get coverage metricc on osx or linux from the build folder

> ./tests

> gcov ../src/*.cpp --object-directory CMakeFiles/tests.dir/

To get nicer html format

>gcovr -r ../src --object-directory ./CMakeFiles/tests.dir/ --html --html-details -o output.html

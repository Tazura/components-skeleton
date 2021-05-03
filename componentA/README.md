# componentA

## Description
This component is used for ....
* componentA-lib
  * Shared library for componentA
* componentA-slib
  * Static library for componentA

## Configuration
The configuration files are in /etc/componentA/

## Compiling
Required components: 
* boost
* fakeit
* gtest

Create an out of source build directory.
Then call cmake with the source directory.
```
cd componentA
mkdir build
cd build
cmake ..
make
```

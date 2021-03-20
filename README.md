# helloqt
Simple demo to show how to test a Qt Widget with Google Test.

## Setup Instructions
### Qt Installation
Use the Qt Maintance Tool to install the latest version of the Qt Framework.

### Conan
```shell
pip install --user --upgrade conan
```

## Build Instructions

```shell
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH=<Qt Installation Dir>
cmake --build . --target all test
```

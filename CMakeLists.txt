cmake_minimum_required( VERSION 3.17 )

if( NOT CMAKE_PREFIX_PATH)
    message( ERROR "CMAKE_PREFIX_PATH is not defined, you may need to set it "
             "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)" )
endif()

project( helloqt )

if( NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake" )
    message( STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan" )
    file( DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.16.1/conan.cmake"
          "${CMAKE_BINARY_DIR}/conan.cmake"
          TLS_VERIFY ON )
endif()

list( APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} )

include( cmake/compiler_settings.cmake )
include( ${CMAKE_BINARY_DIR}/conan.cmake )

conan_cmake_configure( REQUIRES
                       gtest/1.10.0
                       GENERATORS cmake_find_package
                       )
conan_cmake_autodetect( CONAN_SETTINGS )

conan_cmake_install( PATH_OR_REFERENCE ${CMAKE_BINARY_DIR}
                     BUILD missing
                     SETTINGS ${CONAN_SETTINGS} )

find_package( Qt5 COMPONENTS Widgets Test REQUIRED )

add_subdirectory( src )
enable_testing()
add_subdirectory( tests )


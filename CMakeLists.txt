cmake_minimum_required( VERSION 3.17 )

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
                       qt/6.2.1
                       gtest/1.10.0
                       GENERATORS cmake_find_package
                       OPTIONS qt:shared=True
                       )
conan_cmake_autodetect( CONAN_SETTINGS )

conan_cmake_install( PATH_OR_REFERENCE ${CMAKE_BINARY_DIR}
                     BUILD missing
                     SETTINGS ${CONAN_SETTINGS} )

find_package( Qt6 COMPONENTS Widgets Test REQUIRED )

add_subdirectory( src )
enable_testing()
add_subdirectory( tests )



add_subdirectory( lib )

set( SRCS
     main.cpp )

add_executable( helloqt )
target_sources( helloqt PRIVATE ${SRCS} )
target_link_libraries( helloqt PRIVATE widgets )

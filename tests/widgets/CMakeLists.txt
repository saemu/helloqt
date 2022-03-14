
set( SRCS
     main.cpp
     demowidgettest.cpp )

add_executable( widgettests )
target_sources( widgettests PRIVATE ${SRCS} )
target_link_libraries( widgettests PRIVATE widgets GTest::gtest Qt6::Test )

add_test( NAME widgettests
          COMMAND widgettests -platform offscreen )

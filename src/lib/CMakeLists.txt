
set( SRCS
     demowidget.cpp )

set( MOC_HDRS
     demowidget.h )

set( UI_FILES
     demowidget.ui )

qt6_wrap_ui( SRCS ${UI_FILES} )
qt6_wrap_cpp( SRCS ${MOC_HDRS} )

add_library( widgets STATIC )
target_sources( widgets PRIVATE ${SRCS} ${MOC_HDRS} ${UI_FILES} )
target_include_directories( widgets
                            PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
                            PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )
target_link_libraries( widgets PUBLIC Qt6::Widgets compiler_settings )


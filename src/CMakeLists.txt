add_definitions( "-g -export-dynamic" )
FIND_PACKAGE(Boost 1.41 COMPONENTS filesystem system thread REQUIRED)
pkg_check_modules(GSTMM REQUIRED gstreamermm-0.10)

link_directories(${GTKMM_LIBRARY_DIRS}  ${GSTMM_INCLUDE_DIRS})

include_directories(${GTKMM_INCLUDE_DIRS} ${GSTMM_INCLUDE_DIRS} )

add_executable(mtc_client main.cpp)

target_link_libraries(mtc_client ${GTKMM_LIBRARIES} ${GSTMM_LIBRARIES} ${Boost_LIBRARIES} )

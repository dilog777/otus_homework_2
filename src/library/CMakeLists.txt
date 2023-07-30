file(GLOB_RECURSE SRC *.h *.hpp *.cpp)

add_library(ip_filter_lib ${SRC})

target_include_directories(ip_filter_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

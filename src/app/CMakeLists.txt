file(GLOB_RECURSE SRC *.h *.hpp *.cpp)

add_executable(ip_filter ${SRC})

target_link_libraries(ip_filter PRIVATE
	ip_filter_lib
)

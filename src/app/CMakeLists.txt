file(GLOB_RECURSE SRC *.h *.hpp *.cpp)

add_executable(ip_filter ${SRC})

set_target_properties(ip_filter PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
)

if (MSVC)
	target_compile_options(ip_filter PRIVATE /W4)
else ()
	target_compile_options(ip_filter PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

target_include_directories(ip_filter PRIVATE
	../library
)

target_link_libraries(ip_filter PRIVATE
	ip_filter_lib
)

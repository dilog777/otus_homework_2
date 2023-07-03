file(GLOB_RECURSE SRC *.h *.hpp *.cpp)

add_library(ip_filter_lib ${SRC})

set_target_properties(ip_filter_lib PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
)

if (MSVC)
	target_compile_options(ip_filter_lib PRIVATE /W4)
else ()
	target_compile_options(ip_filter_lib PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

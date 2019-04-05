set(tinyxml_SRC
        tinystr.cpp tinystr.h
        tinyxml.cpp tinyxml.h
        tinyxmlerror.cpp
        tinyxmlparser.cpp
	)

add_library(tinyxml STATIC ${tinyxml_SRC})
target_compile_definitions(tinyxml PUBLIC TIXML_USE_STL)
target_include_directories(tinyxml PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

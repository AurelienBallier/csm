SET(options_linker_flags "")
if(MSVC)
SET_SOURCE_FILES_PROPERTIES(test_options.c options.c options_interface.c PROPERTIES LANGUAGE CXX)
SET(options_linker_flags csm)
endif(MSVC)

SET(options_sources options.c options_interface.c )
ADD_LIBRARY(options STATIC ${options_sources})

ADD_EXECUTABLE(test_options test_options.c)
TARGET_LINK_LIBRARIES(test_options options ${options_linker_flags})

# installation

FILE(GLOB headers "*.h")
INSTALL(FILES ${headers} DESTINATION include/options)
INSTALL(TARGETS options ARCHIVE DESTINATION lib)

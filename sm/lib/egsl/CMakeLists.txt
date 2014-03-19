
SET(egsl_sources 
	egsl.c 
	egsl_ops.c
	egsl_conversions.c
	egsl_misc.c
)

if(MSVC)
SET_SOURCE_FILES_PROPERTIES(${egsl_sources} egsl_test.c egsl_test_allocation.c PROPERTIES LANGUAGE CXX)
SET(egsl_linker_flags csm)
else(MSVC)
SET(egsl_linker_flags ${GSL_LIBRARIES})
endif(MSVC)


ADD_LIBRARY(egsl STATIC ${egsl_sources})

ADD_EXECUTABLE(egsl_test egsl_test.c)
TARGET_LINK_LIBRARIES(egsl_test egsl ${egsl_linker_flags})

ADD_EXECUTABLE(egsl_test_allocation egsl_test_allocation.c)
TARGET_LINK_LIBRARIES(egsl_test_allocation egsl ${egsl_linker_flags})


# installation

FILE(GLOB headers "*.h")
INSTALL(FILES ${headers} DESTINATION include/egsl)
INSTALL(TARGETS egsl ARCHIVE DESTINATION lib)

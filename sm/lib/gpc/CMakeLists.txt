
SET(gpc_sources
	gpc.c
	gpc_utils.c
)

if(MSVC)
SET_SOURCE_FILES_PROPERTIES(${gpc_sources} PROPERTIES LANGUAGE CXX)
endif(MSVC)

ADD_LIBRARY(gpc STATIC  ${gpc_sources})

#ifndef SM_LOGGING_H
#define SM_LOGGING_H

#include "restrict.h"

extern const char * sm_program_name;

CSM_LIB_DECL void sm_set_program_name(const char*);

CSM_LIB_DECL void sm_debug(const char *msg, ...);
CSM_LIB_DECL void sm_error(const char *msg, ...);
CSM_LIB_DECL void sm_info(const char *msg, ...);

/* Optional context handling for hyerarchical display */
CSM_LIB_DECL void sm_log_push(const char*);
CSM_LIB_DECL void sm_log_pop();

/* Enable/disable writing of debug information */
CSM_LIB_DECL void sm_debug_write(int enabled);



/* Private interface */
CSM_LIB_DECL void sm_write_context();
CSM_LIB_DECL void check_for_xterm_color();
	
#endif

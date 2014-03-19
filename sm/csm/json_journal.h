#ifndef H_JSON_JOURNAL
#define H_JSON_JOURNAL

#include <stdio.h>

#include <json-c/json.h>
#include <json-c/json_more_utils.h>

#include "laser_data_json.h"

#include "restrict.h"

/** This is a collection of functions for debugging purposes only.
    It's a little cryptic, but if you don't understand them, don't worry.

	The information used by this is used primarily to create the
	icp animation videos.
*/

/** Public interface */

	#define JJ jj_enabled()
	CSM_LIB_DECL int jj_enabled(void);

	CSM_LIB_DECL void jj_context_enter(const char*context_name);
	CSM_LIB_DECL void jj_context_exit(void);

	CSM_LIB_DECL void jj_loop_enter(const char*loop_name);
	CSM_LIB_DECL void jj_loop_iteration(void);
	CSM_LIB_DECL void jj_loop_exit(void);

	CSM_LIB_DECL void jj_add_int(const char*name, int);
	CSM_LIB_DECL void jj_add_double(const char*name, double);
	CSM_LIB_DECL void jj_add_double_array(const char*name, double*,int);
	CSM_LIB_DECL void jj_add_int_array(const char*name, int*,int);
	CSM_LIB_DECL void jj_add(const char*name, JO);

	CSM_LIB_DECL void jj_set_stream(FILE*);
	CSM_LIB_DECL FILE*  jj_get_stream(void);

/**** Private functions */

	/** (private) Gets the top of the stack. */
	CSM_LIB_DECL JO jj_stack_top(void);
	/** (private) Pushes an object onto the stack. */
	CSM_LIB_DECL void jj_stack_push(JO jo);
	CSM_LIB_DECL void jj_stack_pop(void);
	/** (private) Asserts if the stack top is not an hash. */
	CSM_LIB_DECL void jj_must_be_hash(void);
	/** (private) Asserts if the stack top is not an array. */
	CSM_LIB_DECL void jj_must_be_array(void);


#endif

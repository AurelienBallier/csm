#ifndef H_SM_UTILS
#define H_SM_UTILS

#include <stdio.h>

/** Tries to open a file for reading; if filename == "-" or "stdin", returns
    standard input. An error message is printed in case of error. */
CSM_LIB_DECL FILE * open_file_for_reading(const char*filename);

/** Tries to open a file for reading; if filename == "-" | "stdout", returns
    standard output. If it's "stderr" same.  
    An error message is printed in case of error. */
CSM_LIB_DECL FILE * open_file_for_writing(const char*filename);

/* Could you believe there isn't a portable implementation of these? */

/* TODO: switch for windows */
#define DIR_SEPARATOR '/' 

/*  "dir/base.suf" -> "base.suf" */
CSM_LIB_DECL void my_basename(const char *file, char*dest);
/*  "dir/base.suf" -> "base" */
CSM_LIB_DECL void my_basename_no_suffix(const char *file, char*dest);
/*  "dir/base.suf" -> "dir/base" */
CSM_LIB_DECL void my_no_suffix(const char *file, char*dest);

CSM_LIB_DECL char * my_strdup(const char *s);

#endif

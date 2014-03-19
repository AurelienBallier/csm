/* Some preprocessor magic for having fast inline functions. */
#ifndef RESTRICT_H
#define RESTRICT_H

#include <gsl/gsl_matrix.h>

#ifndef INLINE
#define INLINE static inline
#endif
#ifndef INLINE_DECL
#define INLINE_DECL static inline
#endif

#ifdef __cplusplus
#ifdef _MSC_VER
    #if defined (csm_EXPORTS) || defined (csm_static_EXPORTS)
    #define CSM_LIB_DECL extern "C" __declspec(dllexport)
    #else
    #define CSM_LIB_DECL extern "C"
    //#define CSM_LIB_DECL extern "C" __declspec(dllimport)
    #endif
#else
    #define CSM_LIB_DECL extern "C"
#endif
#else
    #define CSM_LIB_DECL 
#endif

/* Some preprocessor magic for the "restrict" keyword:
	http://www.cellperformance.com/mike_acton/2006/05/demystifying_the_restrict_keyw.html */
#if __STDC_VERSION__ >= 199901
#elif defined (__GNUC__) && __GNUC__ >= 2 && __GNUC_MINOR__ >= 91
	#define restrict __restrict__
#else
	#define restrict
#endif

/* Some preprocessor magic for calling this library from C++ */

#ifdef __cplusplus
	#define restrict /* nothing */
#endif

#ifdef __cplusplus
    #include <cstring>

    #define DYNAMIC_ALLOCATE(TYPE, VAR, SIZE) TYPE *VAR = new TYPE[SIZE]
    #define CLEAN_MEMORY(VAR) delete [] VAR
#else
	#define DYNAMIC_ALLOCATE(TYPE, VAR, SIZE) TYPE VAR[SIZE]
    #define CLEAN_MEMORY(TYPE, VAR)
#endif

#ifdef _WIN32
#include <ctype.h>

CSM_LIB_DECL int strcasecmp(const char* s1, const char* s2);
#endif

#endif //RESTRICT_H

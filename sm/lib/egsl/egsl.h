#ifndef H_EASY_GSL
#define H_EASY_GSL

#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>

#include "../../csm/restrict.h"

struct egsl_val {
	gsl_matrix * gslm;
	int cid : 16;
	int index : 16;
};

typedef struct egsl_val val;

/* Core functions */

/* Push a new context. */
CSM_LIB_DECL void egsl_push();
CSM_LIB_DECL void egsl_push_named(const char*name);
/* Pops a context */
CSM_LIB_DECL void egsl_pop();
CSM_LIB_DECL void egsl_pop_named(const char*name);
CSM_LIB_DECL void egsl_free(void);

CSM_LIB_DECL double* egsl_atmp(val v, size_t i, size_t j);
CSM_LIB_DECL val egsl_alloc(size_t rows, size_t columns);
CSM_LIB_DECL val egsl_alloc_in_context(int cid, size_t rows, size_t cols);
CSM_LIB_DECL gsl_matrix * egsl_gslm(val v);
/** Creates a copy of v in the previous context.*/
CSM_LIB_DECL val egsl_promote(val v);

/** Operations among values */
CSM_LIB_DECL val egsl_scale(double, val);
CSM_LIB_DECL val egsl_sum(val, val);
CSM_LIB_DECL val egsl_sum3(val, val, val);
CSM_LIB_DECL val egsl_mult(val, val);
CSM_LIB_DECL val egsl_transpose(val);
CSM_LIB_DECL val egsl_inverse(val);
CSM_LIB_DECL val egsl_sub(val,val);
CSM_LIB_DECL val egsl_sum(val v1,val v2);
CSM_LIB_DECL val egsl_compose_col(val v1, val v2);
CSM_LIB_DECL val egsl_compose_row(val v1, val v2);
CSM_LIB_DECL void egsl_add_to(val v1, val v2);
CSM_LIB_DECL void egsl_add_to_col(val v1, size_t j, val v2);

CSM_LIB_DECL double egsl_norm(val);

CSM_LIB_DECL void egsl_symm_eig(val v, double* eigenvalues, val* eigenvectors);

CSM_LIB_DECL double egsl_atv(val, size_t i);
CSM_LIB_DECL double egsl_atm(val, size_t i, size_t j);

/* File: egsl_conversions.c
  Conversions */

CSM_LIB_DECL val egsl_vFa(size_t rows, const double*);
CSM_LIB_DECL val egsl_vFda(size_t rows, size_t columns, const double*);

/** Copies a VECTOR value into array */
CSM_LIB_DECL void egsl_v2a(val, double*);
/** Copies a MATRIX value into array (row1 .. rown) */
CSM_LIB_DECL void egsl_v2da(val, double*);
/** Copies a vector value into a gsl_vector */
CSM_LIB_DECL void egsl_v2vec(val, gsl_vector*);

CSM_LIB_DECL val egsl_vFgslv(const gsl_vector*);
CSM_LIB_DECL val egsl_vFgslm(const gsl_matrix*);

CSM_LIB_DECL gsl_matrix* egsl_v2gslm(val);

/*/ File: egsl_misc.c
    Miscellaneous useful matrixes. */
CSM_LIB_DECL val egsl_zeros(size_t rows, size_t columns);
CSM_LIB_DECL val egsl_ones(size_t rows, size_t columns);
CSM_LIB_DECL val egsl_vers(double theta);
CSM_LIB_DECL val egsl_rot(double theta);


/* Misc */
CSM_LIB_DECL void egsl_print(const char*str, val);	
/** Prints eigenvalues and eigenvectors of a symmetric matrix */
CSM_LIB_DECL void egsl_print_spectrum(const char*s, val v);
CSM_LIB_DECL void egsl_print_stats(void);


	
/** Private implementations things */
CSM_LIB_DECL void egsl_expect_size(val v, size_t rows, size_t cols);
CSM_LIB_DECL void egsl_error(void);

#endif

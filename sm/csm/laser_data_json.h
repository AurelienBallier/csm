#ifndef H_LASER_DATA_JSON
#define H_LASER_DATA_JSON

#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>

#include <json-c/json.h>
#include <json-c/json_more_utils.h>

#include "laser_data.h"
#include "algos.h"

/* Laserdata to/from json */

CSM_LIB_DECL JO ld_to_json(LDP);
CSM_LIB_DECL LDP json_to_ld(JO);

CSM_LIB_DECL JO corr_to_json(struct correspondence*, int n);
CSM_LIB_DECL int json_to_corr(JO jo, struct correspondence*, int n);

CSM_LIB_DECL LDP ld_from_json_stream(FILE*);
CSM_LIB_DECL LDP ld_from_json_string(const char*s);
CSM_LIB_DECL void ld_write_as_json(LDP ld, FILE * stream);


/* Other stuff to/from json */

CSM_LIB_DECL JO matrix_to_json(gsl_matrix*m);
CSM_LIB_DECL JO vector_to_json(gsl_vector*v);
CSM_LIB_DECL JO result_to_json(struct sm_params*p, struct sm_result *r);

#endif

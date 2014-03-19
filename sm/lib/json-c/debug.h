/*
 * $Id: debug.h,v 1.5 2006/01/30 23:07:57 mclark Exp $
 *
 * Copyright (c) 2004, 2005 Metaparadigm Pte. Ltd.
 * Michael Clark <michael@metaparadigm.com>
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See COPYING for details.
 *
 */

#ifndef _DEBUG_H_
#define _DEBUG_H_

#include "../../csm/restrict.h"

CSM_LIB_DECL void mc_set_debug(int debug);
CSM_LIB_DECL int mc_get_debug(void);

CSM_LIB_DECL void mc_set_syslog(int syslog);
CSM_LIB_DECL void mc_abort(const char *msg, ...);
CSM_LIB_DECL void mc_debug(const char *msg, ...);
CSM_LIB_DECL void mc_error(const char *msg, ...);
CSM_LIB_DECL void mc_info(const char *msg, ...);

#endif

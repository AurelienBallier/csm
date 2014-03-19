/*
 * $Id: arraylist.c,v 1.4 2006/01/26 02:16:28 mclark Exp $
 *
 * Copyright (c) 2004, 2005 Metaparadigm Pte. Ltd.
 * Michael Clark <michael@metaparadigm.com>
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See COPYING for details.
 *
 */

#include "config.h"

#if STDC_HEADERS
# include <stdlib.h>
# include <string.h>
#endif /* STDC_HEADERS */

#if HAVE_STRINGS_H
# include <strings.h>
#endif /* HAVE_STRINGS_H */

#include "bits.h"
#include "arraylist.h"

struct array_list*
array_list_new(array_list_free_fn *free_fn)
{
  struct array_list *self;

  if(!(self = (struct array_list *)calloc(1, sizeof(struct array_list)))) return NULL;
  self->size = ARRAY_LIST_DEFAULT_SIZE;
  self->length = 0;
  self->free_fn = free_fn;
  if(!(self->array = (void **)calloc(sizeof(void*), (size_t) self->size))) {
    free(self);
    return NULL;
  }
  return self;
}

extern void
array_list_free(struct array_list *self)
{
  int i;
  for(i = 0; i < self->length; i++)
    if(self->array[i]) self->free_fn(self->array[i]);
  free(self->array);
  free(self);
}

void*
array_list_get_idx(struct array_list *self, int i)
{
  if(i >= self->length) return NULL;
  return self->array[i];
}

static int array_list_expand_internal(struct array_list *self, int max)
{
  void *t;
  int new_size;

  if(max < self->size) return 0;
  new_size = max(self->size << 1, max);
  if(!(t = realloc(self->array, new_size*sizeof(void*)))) return -1;
  self->array = (void **)t;
  (void)memset(self->array + self->size, 0, (new_size-self->size)*sizeof(void*));
  self->size = new_size;
  return 0;
}

int
array_list_put_idx(struct array_list *self, int idx, void *data)
{
  if(array_list_expand_internal(self, idx)) return -1;
  if(self->array[idx]) self->free_fn(self->array[idx]);
  self->array[idx] = data;
  if(self->length <= idx) self->length = idx + 1;
  return 0;
}

int
array_list_add(struct array_list *self, void *data)
{
  return array_list_put_idx(self, self->length, data);
}

int
array_list_length(struct array_list *self)
{
  return self->length;
}

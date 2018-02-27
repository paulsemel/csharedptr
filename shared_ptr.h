#pragma once
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct meta {
    size_t count;
};

void clean_this_shit(void *ptr)
{
    char *t = *(char **)ptr;
    struct meta *tmp = (struct meta *)(t - sizeof(*tmp));
    if ( !(--tmp->count) )
        free(tmp);
}

#define shared __attribute__((cleanup(clean_this_shit)))

#define make_shared(Type, elt) ({    \
    struct meta tmp_s = {           \
        .count = 1                  \
    };                              \
    char *res = malloc((sizeof(Type) * (elt)) + sizeof(struct meta)); \
    memcpy(res, &tmp_s, sizeof(tmp_s)); \
    (void *)(res + sizeof(tmp_s)); \
})

#define reference(ptr) ({\
    char *t = (char *)ptr; \
    struct meta *tmp = (struct meta *)(t - sizeof(struct meta)); \
    tmp->count++; \
    ptr; \
})


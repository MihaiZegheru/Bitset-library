/*
 *   Copyright (c) 2023 Mihai Zegheru
 *   All rights reserved.
 */

#ifndef BITSET_H__
#define BITSET_H__

#include <stddef.h>
#include <stdint.h>

#ifndef BITSET_MALLOC
#include <stdlib.h>
#define BITSET_MALLOC malloc
#endif // BITSET_MALLOC

#ifndef BITSET_FREE
#include <stdlib.h>
#define BITSET_FREE free
#endif // BITSET_FREE

#define BITSET_GET_CELL(i, bitset) (i) / sizeof(*(bitset).bytes)
#define BITSET_GET_OFFSET(i, bitset) (i) % sizeof(*(bitset).bytes)

typedef struct {
    uint8_t *bytes;
    size_t size;
} bitset_t;

bitset_t bitset_new(size_t size);
void bitset_delete(bitset_t bitset);

uint8_t bitset_get(size_t i, bitset_t bitset);
void bitset_set(size_t i, bitset_t bitset);
void bitset_reset(size_t i, bitset_t bitset);
void bitset_toggle(size_t i, bitset_t bitset);

#endif // BITSET_H__

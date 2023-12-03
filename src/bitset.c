/*
 *   Copyright (c) 2023 Mihai Zegheru
 *   MIT licensed
 */

#include "../include/bitset.h"

bitset_t bitset_new(size_t size)
{
    bitset_t bitset;
    bitset.size = size;
    bitset.bytes = BITSET_MALLOC(size * sizeof(*bitset.bytes));

    return bitset;
}

void bitset_delete(bitset_t bitset)
{
    BITSET_FREE(bitset.bytes);
}

uint8_t bitset_get(size_t i, bitset_t bitset)
{
    return (bitset.bytes[BITSET_GET_CELL(i, bitset)] >>
            BITSET_GET_OFFSET(i, bitset)) & 1;
}

void bitset_set(size_t i, bitset_t bitset)
{
    bitset.bytes[BITSET_GET_CELL(i, bitset)] = 
            bitset.bytes[BITSET_GET_CELL(i, bitset)] | 
            (1 << BITSET_GET_OFFSET(i, bitset)); 
}

void bitset_reset(size_t i, bitset_t bitset)
{
    bitset.bytes[BITSET_GET_CELL(i, bitset)] = 
            bitset.bytes[BITSET_GET_CELL(i, bitset)] &
            ~(1 << BITSET_GET_OFFSET(i, bitset)); 
}

void bitset_toggle(size_t i, bitset_t bitset)
{
    bitset.bytes[BITSET_GET_CELL(i, bitset)] = 
            bitset.bytes[BITSET_GET_CELL(i, bitset)] ^
            (1 << BITSET_GET_OFFSET(i, bitset)); 
}

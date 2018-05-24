#pragma once
#include "bitmap.h"

#define BITMAPMAXSIZE 10000
#define bloomhashcount 2

typedef uint64_t(*bloomhash)(const char*);
typedef struct bloomfilter{
    bitmap bm;
    bloomhash bloom_hash[bloomhashcount];
}bloomfilter;

void bloomfilterinit(bloomfilter *bf);
void bloomfilterdestroy(bloomfilter *bf);
void bloomfilterinsert(bloomfilter *bf,const char *str);
int bloomfilterisexist(bloomfilter *bf,const char *str);


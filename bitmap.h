#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <stdint.h>

typedef uint64_t bitmaptype;
typedef struct bitmap{
    bitmaptype *data;
    uint64_t capacity;
}bitmap;
void bitmapinit(bitmap *bm,uint64_t capacity);
void bitmapdestroy(bitmap *bm);
void bitmapset(bitmap *bm,uint64_t index);
void bitmapunset(bitmap *bm,uint64_t index);
void bitmapfill(bitmap *bm,uint64_t capacity);
void bitmapclear(bitmap *bm,uint64_t capacity);
uint64_t bitmaptest(bitmap *bm,uint64_t index);

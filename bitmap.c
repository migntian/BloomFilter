#include <stdio.h>
#include "bitmap.h"

void bitmapinit(bitmap *bm,uint64_t capacity)
{
    if(bm == NULL)
    {
        return;
    }
    bm->capacity = capacity;
    uint64_t size = capacity/(sizeof(bitmaptype)*8)+1;
    bm->data = (bitmaptype *)malloc(sizeof(bitmaptype)*size);
    memset(bm->data,0,sizeof(bitmaptype)*size);
}
//uint64_t getsize(uint64_t capacity)
//{
//    uint64_t ret = capacity/(sizeof(bitmaptype)*8)+1;
//    return ret;
//}
void bitmapdestroy(bitmap *bm)
{
    if(bm == NULL)
    {
        return;
    }
    bm->capacity = 0;
    free(bm->data);
    return;
}
uint64_t bitmaptest(bitmap *bm,uint64_t index)
{
    if(bm == NULL || index >= bm->capacity)
    {
        return;
    }
    uint64_t n,offset;
    n = index/(sizeof(bitmaptype)*8);
    offset = index % (sizeof(bitmaptype)*8);
    u_int64_t ret = bm->data[n] & (0x1ul << offset);
    return ret > 0 ? 1 : 0;


}
//void getoffset(uint64_t index,uint64_t* n,uint64_t *offset)
//{
//    *n = index/(sizeof(bitmaptype)*8);
//    *offset = index %(sizeof(bitmaptype)*8);
//    
//}
void bitmapset(bitmap *bm,uint64_t index)
{
    if(bm == NULL)
    {
        return;
    }
    uint64_t n,offset;
    n = index/(sizeof(bitmaptype)*8);
    offset = index % (sizeof(bitmaptype)*8);
    bm->data[n] |= 0x1ul << offset;
    return;

}
void bitmapunset(bitmap *bm,uint64_t index)
{
    if(bm == NULL)
    {
        return;
    }
    uint64_t n,offset;
    n = index/(sizeof(bitmaptype)*8);
    offset = index % (sizeof(bitmaptype)*8);
    bm->data[n] &=  ~(0x1ul << offset);
    return;

}
void bitmapfill(bitmap *bm,uint64_t capacity)
{
    if(bm == NULL)
    {
        return;
    }
    uint64_t size = capacity/(sizeof(bitmaptype)*8)+1;
    memset(bm->data,0xff,sizeof(bitmaptype)*size);
    return;
    
    
}
void bitmapclear(bitmap *bm,uint64_t capacity)
{
    if(bm == NULL)
    {
        return;
    }
    uint64_t size = capacity/(sizeof(bitmaptype)*8)+1;
    memset(bm->data,0x0,sizeof(bitmaptype)*size);
    return;
    
}
//#define HEADER printf("\n============%s=============\n",__FUNCTION__)
//
//void testbitmaptest()
//{
//    HEADER;
//    bitmap bitmap;
//    bitmapinit(&bitmap,100);
//    int ret = bitmaptest(&bitmap,50);
//    printf("excpted ret is 0,actul is %d\n",ret);
//
//}
//void testbitmapset()
//{
//    HEADER;
//    bitmap bitmap;
//    bitmapinit(&bitmap,100);
//    int ret1 = bitmaptest(&bitmap,50);
//    printf("excpted ret1 is 0,actul is %d\n",ret1);
//    bitmapset(&bitmap,50);
//    int ret2 = bitmaptest(&bitmap,50);
//    printf("excpted ret2 is 1,actul is %d\n",ret2);
//
//}
//void testbitmapunset()
//{
//    HEADER;
//    bitmap bitmap;
//    bitmapinit(&bitmap,100);
//    int ret1 = bitmaptest(&bitmap,50);
//    printf("excpted ret1 is 0,actul is %d\n",ret1);
//    bitmapset(&bitmap,50);
//    int ret2 = bitmaptest(&bitmap,50);
//    printf("excpted ret2 is 1,actul is %d\n",ret2);
//    bitmapunset(&bitmap,50);
//    int ret3 = bitmaptest(&bitmap,50);
//    printf("excpted ret3 is 0,actul is %d\n",ret3);
//
//}
//void testbitmapfill()
//{
//    HEADER;
//    bitmap bitmap;
//    bitmapinit(&bitmap,100);
//    int ret1 = bitmaptest(&bitmap,50);
//    printf("excpted ret1 is 0,actul is %d\n",ret1);
//    bitmapfill(&bitmap,100);
//    int ret2 = bitmaptest(&bitmap,50);
//    printf("excpted ret2 is 1,actul is %d\n",ret2);
//
//
//}
//void testbitmapclear()
//{
//    HEADER;
//    bitmap bitmap;
//    bitmapinit(&bitmap,100);
//    int ret1 = bitmaptest(&bitmap,50);
//    printf("excpted ret1 is 0,actul is %d\n",ret1);
//    bitmapfill(&bitmap,100);
//    int ret2 = bitmaptest(&bitmap,50);
//    printf("excpted ret2 is 1,actul is %d\n",ret2);
//    bitmapclear(&bitmap,100);
//    int ret3 = bitmaptest(&bitmap,50);
//    printf("excpted ret3 is 0,actul is %d\n",ret3);
//
//
//}
//int main()
//{
//    testbitmaptest();
//    testbitmapset();
//    testbitmapunset();
//    testbitmapfill();
//    testbitmapclear();
//    return;
//}

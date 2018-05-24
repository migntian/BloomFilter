#include "bloomfilter.h"
#include "bitmap.c"

size_t BKDRHash(const char *str)
{
    size_t hash = 0;
    size_t ch = 0;
    while(ch = (size_t)*str++)//此函数的计算方式就是依次取字符串的ASCLL码
    {
        hash = hash * 131 + ch;
    }
    return hash;
}
size_t SDBMHash(const char *str)
{
    size_t hash = 0;
    size_t ch = 0;
    while(ch = (size_t)*str++)//此函数的计算方式就是依次取字符串的ASCLL码
    {
        hash = hash * 65599 + ch;
    }
    return hash;
}
void bloomfilterinit(bloomfilter *bf)
{
    if(bf == NULL)
    {
        return;
    }
    bitmapinit(&bf->bm,10000);
    bf->bloom_hash[0] = SDBMHash;
    bf->bloom_hash[1] = BKDRHash;
    return;
}

void bloomfilterdestroy(bloomfilter *bf)
{
    if(bf == NULL)
    {
        return;
    }
    bitmapdestroy(&bf->bm);
    bf->bloom_hash[0] = NULL;
    bf->bloom_hash[1] = NULL;
    return;
    
}
void bloomfilterinsert(bloomfilter *bf,const char *str)
{
    if(bf == NULL || str == NULL)
    {
        return;
    }
    uint64_t i = 0;
    for(;i < bloomhashcount;i++)
    {
        uint64_t hash = bf->bloom_hash[i](str)%BITMAPMAXSIZE;
        bitmapset(&bf->bm,hash);
    }
    return;
    
}
int bloomfilterisexist(bloomfilter *bf,const char *str)
{
    if(bf == NULL || str == NULL)
    {
        return 0;
    }
    uint64_t i = 0;
    for(;i < bloomhashcount;i++)
    {
        uint64_t hash = bf->bloom_hash[i](str)%BITMAPMAXSIZE;
        int ret = bitmaptest(&bf->bm,hash);
        if(ret == 0)
        {
            return 0;
        }
    }
    return 1;

}
//test
//////////////////////
#define HEADER printf("\n============%s============\n",__FUNCTION__)
void bloomfiltertest()
{
    HEADER;
    bloomfilter bloom;
    bloomfilterinit(&bloom);
    bloomfilterinsert(&bloom,"hehe");
    bloomfilterinsert(&bloom,"haha");
    int ret = bloomfilterisexist(&bloom,"hehe");
    printf("expected ret is 1,actul is %d\n",ret);
}
int main()
{
    bloomfiltertest();
    return 0;
}

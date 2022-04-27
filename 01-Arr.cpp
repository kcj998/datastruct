#include <cstdio>
#include <malloc.h>
struct Arr
{
    int *pBase;//定义第一个元素的地址
    int len;  // 数组所能容纳的最大元素个数
    int cnt; // 当前数组有效元素个数
};
// 数组初始化
void init_arr(struct Arr *pArr, int length)
{
    //根据数组的长度，分配的内存pBase
    pArr->pBase = (int *) malloc(sizeof(int ) * length);
    if (nullptr == pArr->pBase)
    {
        printf("内存分配失败");
        exit(-1);
    }
    // 内存分配成功
    pArr->len = length;
    pArr->cnt = 0;
}
// 判断数组空or满
bool is_empty(struct Arr *pArr)
{
    //数组为空
    if(0 == pArr->cnt)
    {
        return true;
    }
    //不为空
    else
    {
        return false;
    }
}
//满
bool is_full(struct Arr *pArr)
{
    if(pArr->cnt == pArr->len)
    {
        return true;
    }//满
    else
    {
        return false;
    }//未满
}
//遍历数组
void traverse_arr(struct Arr *pArr)
{
    for (int i = 0; i < pArr->cnt; i++)
    {
        printf("%d\t", pArr->pBase[i]);
    }
    printf("\n");
}
//在末尾添加元素
bool append_arr(struct Arr *pArr, int val)
{
    //判断数组是否已满
    if(is_full(pArr))
    {
        return false;  //满
    }
    //未满 添加
    pArr->pBase[pArr->cnt] = val;
    (pArr->cnt)++;  //数组扩容^^^^
    return true;
}
//特定位置插入元素
bool insert_arr(struct Arr *pArr, int pos, int val)
{
    //判断数组是否已满
    if(is_full(pArr))
    {
        return false;  //满
    }
    //判断插入位置是否合法
    if(pos < 0 || pos > pArr->cnt)
    {
        return false;
    }
    // 从最后一个元素的位置开始，到要插入的位置，挨个将数组元素往后移一位
    for (int i = pArr->cnt - 1; i >= pos; --i)
    {
        pArr->pBase[i + 1] = pArr->pBase[i];
    }
    // 将插入的值，赋在指定的位置
    pArr->pBase[pos] = val;
    // 标记数组有效元素的字段加1
    (pArr->cnt)++;
    return true;
}
//删除
bool delete_arr(struct Arr *pArr, int pos,int *pVal)
{
    //判断数组是否已满
    if(is_full(pArr))
    {
        return false;  //满
    }
    //判断插入位置是否合法
    if(pos < 0 || pos > pArr->cnt)
    {
        return false;
    }
    // 将删除的元素的值赋给传进来的指针变量
    *pVal = pArr->pBase[pos];
    // 从到要删除的位置开始，一直到最后一个位置，将数组元素挨个往前移动
    for (int i = pos; i < pArr->cnt; ++i)
    {
        pArr->pBase[i] = pArr->pBase[i+1];
    }
    pArr->cnt--;
    return true;
}
//数组倒置   123456 ---> 654321
void inverse_arr(struct Arr *pArr)
{
    int i = 0;
    int j = pArr->cnt -1;
    int t;
    while(i < j)
    {
        t = pArr->pBase[i];
        pArr->pBase[i] = pArr->pBase[j];
        pArr->pBase[j] = t;
        ++i;
        --j;
    }
    }
//数组排序
void sort_arr(struct Arr *pArr)
{
    int i, j, t;
    for (i = 0; i < pArr->cnt; i++)
    {
        for (j = i + 1; j < pArr->cnt; j++)
        {
            if (pArr->pBase[i] > pArr->pBase[j])
            {
                t = pArr->pBase[i];
                pArr->pBase[i] = pArr->pBase[j];
                pArr->pBase[j] = t;
            }
        }
    }
}
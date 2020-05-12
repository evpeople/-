//常见的操作，打印ADT，删除ADT，找到首次出现的位置，插入删除，返回特定位置的元素
//对于数组，插入删除慢，需要知道总元素的个数
include<stdio.h>
typedef long long ll;
const int maxn = 1000;



int main(void)
{
    
return 0;
}
#include<stdio.h>
 struct node
 {
     int date;
     struct node * next;
 };
typedef struct node * ptr;
typedef ptr list;
typedef ptr position;
int isEmpty(list l)
{
    //此表是否为空表
    return l->next==NULL;
}

int isLast(position a)
{
    //当前位置是否为末尾
    return a->next==NULL;
}

position find(list l, int x)
{
    position temp;
    temp=l->next;
    while (temp!=NULL&&temp->date!=x)
        temp=temp->next; 
    
    return temp;
}
 

//声明指向一个结构体的指针并不能创造该结构体，只是给出足够的空间容纳可能用到的地址，此时必须malloc，但是对于一个沿着表移动的指针，不用malloc
//而对于free而言，指针指向的地址没变，但是此处内容已经没有了意义，不再受到保护，随时可能被更改
//注意，malloc的sizeof里面应该是一个结点，而不是指向节点的指针
//做删除操作之前，先记下下一个节点的位置
 
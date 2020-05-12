#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
typedef long long ll;
const int maxn = 10000;

void bucketsort(int a[],int count)
{
    //桶排序，空间占用极大
    int b[count];
    int count2;//此为整数的个数
    scanf("%d",&count2);
    memset(b,0,count*sizeof(int));
    for (size_t i = 0; i < count2; i++)
    {
        int temp;
        scanf("%d",&temp);
        b[temp]+=1;
    }
    for (size_t i = 0; i < count; i++)
    {
        for (size_t t = 0; t < b[i]; t++)
        {
            printf("%d ",i);//i就是temp，b[i]的值为有多少个temp
        }
    }

/*    
    64 8 216 512 27 729 0 1 343 125



                                                        
      125   216                                             
    0 1     27      343          512   64    729   8           
    如果按照最高位为起点首先018不能，其次27 125  无法分辨
    0 1     2       3      4     5     6     7     8     9
    0 1     512     343    64    125   216   27    8     729       
 
    1            125       
    0      512   729                                                        
    8      216   27             343         64                     
    0      1     2       3      4     5     6     7     8     9
    
*/
}

int main(void)
{
    int a[20];
    bucketsort(a,90);
    getchar();
    return 0;
}
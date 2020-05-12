#include<stdio.h>
#include<time.h>
#define number 1000
int nOfCubed (const int a[],int n)
{
    //从第0项开始加，0，01，012，0123，012……n，1，12，123，这样遍历
    int sum,maxsum,j,k;
    maxsum=0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t t = i; t < n; t++)
        {
            sum=0;
            for (size_t k = i; k <=t; k++)
            {
                sum+=a[k];
            }
            if (sum>maxsum)
           {
                maxsum=sum;
            }
            
            
        }
        
    }
    return maxsum;    
}
int square(const int a[],int n)
{
    //0然后比较，01，比较，0123，比较，也就是在一次循环中同时做了加和比较两件事情，使得立方运行时间变成了平方
    long long  sum,max;
    max=0;
    for (size_t i = 0; i < n; i++)
    {
        sum=0;
        for (size_t t = i; t < n; t++)
        {
            sum+=a[t];
            if (sum>max)
            {
                max=sum;
            }
        

        }
        
    }
    return max;   
}
int max3(int a,int b,int c)
{
    int ans;
    ans=a>b?a:b;
    ans=ans>c?ans:c;
    return ans;
}

int fenzhi(const int a[],int left,int right)
{
    int maxOfLeft=0,maxOfRight=0;
    int maxLeftB=0,maxRightB=0;
    int leftBSum=0,rightBSum=0;
    int center=0,i=0;
    //下面为基准情形，用于退出递归
    if (left==right)
    {
        if (a[left])
        {
            return a[left];
        }else
        {
            return 0;
        }
    }

    center=(left+right)/2;
    maxOfLeft=fenzhi(a,left,center);//通过递归求出纯左边的最大子序列
    maxOfRight=fenzhi(a,center+1,right);//通过递归求出纯右边的最大子序列

    maxLeftB=0;
    leftBSum=0;
    for ( i = center; i >= left; i--)
    {
        leftBSum+=a[i];
        if (leftBSum>maxLeftB)
        {
            maxLeftB=leftBSum;
        }
    }

    maxRightB=0;
    rightBSum=0;
    for ( i = center+1; i <= right; i++)
    {
        rightBSum+=a[i];
        if (rightBSum>maxRightB)
        {
            maxRightB=rightBSum;
        }

    }
   return max3(maxOfLeft,maxOfRight,maxRightB+maxLeftB) ;
    
}
int fengz(const a[],int n)
{
    return fenzhi(a,0,n-1);
}
int xianxingjiansuanfa(const int a[],int n)
{

    int sum=0,max=0;
    for (size_t i = 0; i < n; i++)
    {
        sum+=a[i];

        if (sum>max)
        {
            max=sum;
        }else if (sum<0)
        {
            sum=0;
        }
        
        
    }
    
}
int main(void)
{
    int a[number];
    int temp;
    for (size_t i = 0; i < number; i++)
    {
        a[i]=i;
        temp+=i;
    }
    long long ans;
    clock_t be,en;
    be=clock();
    ans=fenzhi(a,0,number-1);
    en=clock();
    printf("%lld\n",ans);
    printf("running time %ld\n",en-be);  
    
    be=clock();
    ans=square(a,number);
    en=clock();
    printf("%lld\n",ans);
    printf("running time %ld\n",en-be);
    
    be=clock();
    ans=nOfCubed(a,number);
    en=clock();
    printf("%lld\n",ans);
    printf("running time %ld\n",en-be);

    ans=0;    
    for (size_t i = 0; i < number; i++)
    {
        ans+=i;
    }
    printf("%d",ans);
    
    getchar();

}
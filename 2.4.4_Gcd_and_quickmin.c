//欧几里得算法求公因数，以及快速幂
int gcd(int m ,int n)
{
    int rem;
    while (n>0)
    {
        rem=m%n;
        m=n;
        n=rem;
    }
    return m;
}
int qiumi(long int x,int n)
{
    //复杂度为log（n）
    if (n==0)
    {
        return 1;
    }
    if (n==1)
    {
        return x;
    }
    if (n%2==0)//偶数
    {
        return qiumi(x*x,n/2);//求x方的n/2次幂。然后x的四次方的n/4次幂，以此类推，得到x的n次幂。
    }else
    {
        return qiumi(x*x,(n)/2)*x;
    }
}
int main()
{

    printf("%d",qiumi(2,10));
    getchar();
}

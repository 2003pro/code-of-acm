#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int Montgomery(int n,int p,int m)
{ //快速计算(n^p)%m的值
      unsignedk=1;
      n%=m;
     while(p!=1)
     {
         if(0!=(p&1))k=(k*n)%m;
         n=(n*n)%m;
         p>>=1;
    }
    return(n*k)%m;
} ;
bool IsPrime(int n)
{
    if ( n < 2 )
    {
        // 小于2的数即不是合数也不是素数
        throw 0;
    }
    static unsigned aPrimeList[] = {
        2, 3, 5, 7, 11, 17, 19, 23, 29, 31, 41,
        43, 47, 53, 59, 67, 71, 73, 79, 83, 89, 97
    };
    const int nListNum = sizeof(aPrimeList) / sizeof(unsigned);
    for (int i=0;i<nListNum;++i)
    {
        // 按照素数表中的数对当前素数进行判断
        if (1!=Montgomery(aPrimeList[i],n-1,n)) // 蒙格马利算法
        {
            return false;
        }
    }
    return true;
}


int main()
{
    int n,n1;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
{
    n1=i*10+7;
    bool k=IsPrime(n1);
    bool k1=IsPrime(n1-4);
    bool k2=IsPrime(n1+4);
    if(k&&k1&&k2) printf("%d",n1);
}
    return 0;
}

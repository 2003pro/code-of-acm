#include <bits/stdc++.h>

using namespace std;
const int maxn = 100010;
int t0,n;
long long t,num[maxn];
long long p[maxn], q[maxn];
int pp, pq, qsz;

bool panduan(int k)
{
    //printf ("k%d:", k);
    memcpy (p, num, sizeof (p));
    memset (q, 0, sizeof (q));
    int ans = 0;
    pp = 0; pq = 0; qsz = 0;
    while (!(pp == n && pq == qsz - 1)) {
        int sum = 0;
        //printf ("pp%d pq%d\n", pp, pq);
        for (int i = 0; i < k; i++) {
            if (pp < n && pq < qsz) {
                if (p[pp] <= q[pq]) {
                    sum += p[pp];
                    pp++;
                }
                else {
                    sum += q[pq];
                    pq++;
                }
            }
            else if (pp < n) {
                sum += p[pp];
                pp++;
            }
            else if (pq < qsz){
                sum += q[pq];
                pq++;
            }
        }
        q[qsz] = sum;
        ans += sum;
        //printf ("sum: %d\n", sum);
        qsz++;
    }
    //printf ("pp%d pq%d\n", pp, pq);
   // printf ("%d\n", ans);
    if (ans <= t) return true;
    else return false;

}

int main()
{
    scanf("%d",&t0);
    for(int o=0;o<t0;o++)
    {
        scanf("%d%I64d",&n,&t);
        for(int i=0;i<n;i++) scanf("%I64d",&num[i]);
        sort (num, num + n);
        int l=2,r=n,mid;
        while(l<r)
        {
            mid=(l+r)/2;
            if(panduan(mid))r=mid;
            else l=mid+1;
        }
        printf("%d\n",r);
    }
    return 0;
}

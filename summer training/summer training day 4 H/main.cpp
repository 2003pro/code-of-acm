#include <bits/stdc++.h>
#define ini(x,y) memset(x,y,sizeof(x))
using namespace std;
int s[200003],a[200003],n,m;
bool cmp(int x,int y){
    return x > y;
}
typedef pair<int,int> p;
int main()
{

    ini(a,0);ini(s,0);
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= n;i++) scanf("%d",&s[i]);
    vector<p> v;
    int x,y;
    scanf("%d %d",&y,&x);
    p pp;pp.first = x,pp.second = y;
    v.push_back(pp);
    for(int i = 1;i < m;i++){
        scanf("%d %d",&y,&x);
        p p1 = v.back();
        while(p1.first <= x&&!v.empty()){
            v.pop_back();
            p1 = v.back();
        }
        p1.first = x,p1.second = y;
        v.push_back(p1);
    }
    int l = v.size();
    vector<int> b;
    if(l > 1){
        for(int i = 0;i < l-1;i++){
            p p2 = v[i],p3 = v[i+1];int j;
            for(j = p2.first;j > 0;j--) {b.push_back(s[j]);}
            if(p2.second == 1)sort(b.begin(),b.end());
            else sort(b.begin(),b.end(),cmp);
            for(int k = 0;k < p2.first;k++) s[k+1] = b[k];
            int cnt = p2.first - p3.first;
            for(int k = 0;k < cnt;k++){
                a[k+p3.first+1] = b[k+p3.first];
            }
            b.clear();
       }
    }
    p p2 = v[l-1];int j;
    for(j = p2.first;j > 0;j--){b.push_back(s[j]);}
    if(p2.second == 1)sort(b.begin(),b.end());
    else sort(b.begin(),b.end(),cmp);
    int cnt = b.size();
    for(int k = 0;k < cnt;k++){
        a[k+j+1] = b[k];
    }
    for(int i = v[0].first+1;i <= n;i++) a[i] = s[i];
    for(int i = 1;i <= n;i++) printf("%d ",a[i]);
    printf("\n");
    return 0;
}

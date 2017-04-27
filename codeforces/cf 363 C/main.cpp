#include <bits/stdc++.h>

using namespace std;
int n,a[100],sum = 0;
vector<int> v;
int main()
{
    scanf("%d",&n);int t;
    for(int i = 0;i < n;i++){
        scanf("%d",&t);
        if(t == 0) sum++;
        v.push_back(t);
    }
    int l = v.size();
    for(int i = 0;i < l-1;i++){
        if(v[i] == 1 && v[i+1] == 3) v[i+1] = 2;
        else if(v[i] == 2 && v[i+1] == 3) v[i+1] = 1;
    }
    for(int i = 0;i < l-1;i++){
        if(v[i] == v[i+1] && v[i]!=3) sum++;
    }

    printf("%d\n",sum);
    return 0;
}

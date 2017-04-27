#include <bits/stdc++.h>
#define iOS ios_base::sync_with_stdio(false)
using namespace std;
string s;
int num;
int a[200003];
priority_queue<int,vector<int>,greater<int> > b;

int main()
{
    cin>>num>>s;
    for(int i = 0;i < num;i++)cin>>a[i];
    for(int i = 0;i < num-1;i++){
        if(s[i] != s[i+1]&&s[i] == 'R') b.push(a[i+1]-a[i]);
    }
    if(b.empty()) cout<<-1<<endl;
    else {
        int l = b.top();int ans;
        if(l%2 == 0)  ans = l / 2;
        else ans = l/2 ;
        printf("%d\n",ans);
    }
    return 0;
}

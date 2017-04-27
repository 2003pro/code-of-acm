#include <bits/stdc++.h>
#define rep(i,j,k) for(int i = (int)j;i < (int)k;i++)
using namespace std;
const int N = 4003;
bitset<1003> a[N],b[N],st;
int main()
{
    int n,m;
    cin>>n>>m;
    rep(i,0,m) cin>>a[i]>>b[i];
    cin>>st;
    while(1){
        bool flag = false;
        rep(i,0,m){
            if((st&a[i]) == a[i] && (st&b[i]) != b[i]){
                st |= b[i];
                flag = true;
            }
        }
        if(!flag) break;
    }
    string ans = st.to_string();
    cout<<string(ans.end()-n,ans.end())<<endl;
    return 0;
}

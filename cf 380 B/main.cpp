#include <bits/stdc++.h>

using namespace std;
int n,m;
int s[1003][1003];
vector<vector<int> > sr;
vector<vector<int> > sc;
vector<int> st;
int srsearch(int n,int k){
    int lb = -1,ub = sr[n].size();
    while(ub - lb > 1){
        int mid = (lb + ub)/2;
        if(sr[n][mid] >= k) ub = mid;
        else lb = mid;
    }
    return ub;
}
int scsearch(int n,int k){
    int lb = -1,ub = sc[n].size();
    while(ub - lb > 1){
        int mid = (lb + ub)/2;
        if(sc[n][mid] >= k) ub = mid;
        else lb = mid;
    }
    return ub;
}
int main()
{
    scanf("%d%d",&n,&m);
    int ans = 0;
    for(int i = 0;i < n;i++){
        if(!st.empty()) st.pop_back();
        st.push_back(i*1000-1);
        sr.push_back(st);
    }
    for(int i = 0;i < m;i++){
        if(!st.empty()) st.pop_back();
        st.push_back(i*1000-1);
        sc.push_back(st);
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            scanf("%d",&s[i][j]);
            if(s[i][j]){
                int ta = i*1000 + j,tb = j*1000 + i;
                sr[i].push_back(ta);
                sc[j].push_back(tb);
            }
        }
    }
    for(int i = 0;i < n;i++){
        int ta = i*1000 + m;
        sr[i].push_back(ta);
    }
    for(int i = 0;i < m;i++){
        int ta = i*1000 + n;
        sc[i].push_back(ta);
    }
//    for(int i = 0;i < sr.size();i++){
//        for(int j = 0;j < sr[i].size();j++) printf("%d ",sr[i][j]);
//        printf("\n");
//    }
//    for(int i = 0;i < sc.size();i++){
//        for(int j = 0;j < sc[i].size();j++) printf("%d ",sc[i][j]);
//        printf("\n");
//    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(s[i][j]){
                int x = srsearch(i,i*1000+j);
                int y = scsearch(j,j*1000+i);
//                printf("%d %d\n",x,y);
                ans += (sr[i][x] - sr[i][x-1] - 1);
                ans += (sr[i][x+1] - sr[i][x] - 1);
                ans += (sc[j][y] - sc[j][y-1] - 1);
                ans += (sc[j][y+1] - sc[j][y] - 1);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}

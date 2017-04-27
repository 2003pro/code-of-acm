#include <bits/stdc++.h>

using namespace std;
string seat[1001];
int main()
{
    int n;scanf("%d",&n);int flag = 0;
    for(int i = 0;i < n;i++) cin>>seat[i];
    for(int i = 0;i < n;i++){
        if(seat[i][0] == 'O' &&seat[i][1] == 'O'){
            const char *t1 = seat[i].c_str();
            char* t = new char[6];
            strcpy(t,t1);
            t[0] = '+',t[1] = '+';
            seat[i] = t;
            flag = 1;
            break;
        }
        else if(seat[i][3] == 'O' &&seat[i][4] == 'O'){
            const char *t1 = seat[i].c_str();
            char* t = new char[6];
            strcpy(t,t1);
            t[3] = '+',t[4] = '+';
            seat[i] = t;
            flag = 1;
            break;
        }
    }
    if(flag) {
        printf("YES\n");
        for(int i = 0;i < n;i++) cout<<seat[i]<<endl;
    }
    else printf("NO\n");
    return 0;
}

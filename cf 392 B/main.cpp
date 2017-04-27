#include <bits/stdc++.h>

using namespace std;
char s[103],mpp[5];
map<char,int> mp,mp2;
int main()
{
    scanf("%s",s);int l = strlen(s);int t = 0;
    char r = 'R',y = 'Y',b = 'B',g = 'G';
//    mp2[r] = 1,mp2[b] = 2,mp2[y] = 3,mp2[g] = 4;
    for(int i = 0;i < l;i+=4){
        if(s[i] != '!') {mp[s[i]] = 1;mpp[1] = s[i];t+=1;break;}
    }
    for(int i = 1;i < l;i+=4){
        if(s[i] != '!') {mp[s[i]] = 2;mpp[2] = s[i];t+=2;break;}
    }
    for(int i = 2;i < l;i+=4){
        if(s[i] != '!') {mp[s[i]] = 3;mpp[3] = s[i];t+=3;break;}
    }
    for(int i = 3;i < l;i+=4){
        if(s[i] != '!') {mp[s[i]] = 4;mpp[4] = s[i];t+=4;break;}
    }
//    printf("%d\n",t);
    if(t != 8){
        if(!mp[r]) mp[r] = 8-t;
        else if(!mp[b]) mp[b] = 8-t;
        else if(!mp[y]) mp[y] = 8-t;
        else if(!mp[g]) mp[g] = 8-t;
    }
//    printf("%d %d %d %d\n",mp[r],mp[b],mp[y],mp[g]);
    int an = 0;
    for(int i = mp[r]-1;i < l;i+=4){
        if(s[i] == '!') an++;
    }
    printf("%d ",an);
    an = 0;
    for(int i = mp[b]-1;i < l;i+=4){
        if(s[i] == '!') an++;
    }
    printf("%d ",an);
    an = 0;
    for(int i = mp[y]-1;i < l;i+=4){
        if(s[i] == '!') an++;
    }
    printf("%d ",an);
    an = 0;
    for(int i = mp[g]-1;i < l;i+=4){
        if(s[i] == '!') an++;
    }
    printf("%d\n",an);
    return 0;
}

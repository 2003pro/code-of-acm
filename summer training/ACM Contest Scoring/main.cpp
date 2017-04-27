#include <iostream>
#include <set>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

set<char> problem;
set<string> done[2000];
int score[2000];
int tag[2000];


void calc(char pid,int sc,string status){
    if(status == "right") {problem.insert(pid);printf("1\n");}
    getchar();
    done[pid].insert(status);
    if(done[pid].find("right") == done[pid].end()){
        tag[pid] ++;
        score[pid] = 0;
    }
    else if(status == "right") score[pid] = sc + tag[pid]*20;
    else {
        tag[pid]++;
        score[pid] += 20;
    }
}

void solve(string s){
    cout<<s;
    char pid ;string status = ""; int minutes = 0;
    int  i = 0;
    for(;s[i] != ' ';++i) minutes = minutes * 10 +(s[i] - '0');
    for(++i;s[i] != ' ';++i) pid = s[i];
    for(i++;s[i] != '\n';i++) status += s[i];
    cout<<status;
    getchar();
    calc(pid,minutes,status);
}

char tmp[33];
string runstatus[103];

int main()
{
    int t = 0;
    memset(score,0,sizeof(score));
    memset(tag,0,sizeof(tag));
    while (strlen(fgets(tmp,14,stdin)) > 4){
        runstatus[t] = tmp;
        t++;
    }
    for(int i = 0;i < t;i++) solve(runstatus[i]);
    int ans = 0,cnt = 0;
    set<char>::iterator it = problem.begin();
    while(it != problem.end()) {
            ans += score[*it];
            cnt ++;
            cout<<*it<<endl;
    }
    printf("%d %d\n",cnt,ans);
    return 0;
}

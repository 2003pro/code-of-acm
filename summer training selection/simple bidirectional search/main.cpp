#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
#include <queue>

using namespace std;

struct  node{
    long long  a[3];
    int dig;
    bool operator  <(const node & other) const{
        if(this->a[0] < other.a[0] ) return true;
        else if(this->a[1] == other.a[1]) {
            if(this->a[1] <other.a[1] ) return true;
            else if(this->a[1] == other.a[1]) {
                if(this->a[2] < other.a[2]) return true;
                else return false;
            }
            else return false;
        }
        else return false;
    }
}A[26];
int  n;
struct node st,en;
set<node> s;
queue <node> p;
queue <node> p1;

void bibfs(){
    en.a[0] = 0; en.a[1] = 0; en.a[2] = 0; st.dig = 0; en.dig = n - 1;
    p.push(st);
    p1.push(en);
    if(n%2 == 0){
        while(!p.empty()){
                struct node t = p.front(); p.pop();
                for(int j = 0;j < 3;j++){
                        struct node nxt = t;
                        nxt.a[j] += A[t.dig].a[j];
                        nxt.dig = t.dig + 1;
                        p.push(nxt);
//                        printf("%I64d %I64d %I64d\n",nxt.a[0],nxt.a[1],nxt.a[2]);
                        if(nxt.dig - 1 == n/2 - 1 ){
//                            printf("--------");
                            struct node tt = nxt;
                            for(int i = 0; i < 3;i++) tt.a[i] = nxt.a[i];
                            s.insert(tt);
                        }
                    }
                if(t.dig > n/2 ) break;
        }
        while(!p1.empty()){
                    struct node t = p1.front(); p1.pop();
                    for(int j = 0;j < 3;j++){
                        struct node nxt = t;
                        nxt.a[j] -= A[t.dig].a[j];
                        nxt.dig = t.dig - 1;
                        p1.push(nxt);
//                        printf("%I64d %I64d %I64d\n",nxt.a[0],nxt.a[1],nxt.a[2]);
                        if(nxt.dig + 1== n/2 ) {
//                            printf("-------11  ");
                            if(s.find(nxt) != s.end()){printf("YES\n");return;}
                        }
                    }
                    if(t.dig < n/2 ) break;
        }
        printf("NO\n"); return;
    }
//        while(!p.empty()||!p1.empty()){
//            if(!p.empty()){
//                struct node t = p.front(); p.pop();
//                for(int j = 0;j < 3;j++){
//                        struct node nxt = t;
//                        nxt.a[j] += A[t.dig].a[j];
//                        nxt.dig = t.dig + 1;
//                        p.push(nxt);
//                        printf("%I64d %I64d %I64d\n",nxt.a[0],nxt.a[1],nxt.a[2]);
//                        if(nxt.dig -1 == n/2-1 ){
//                            printf("--------");
//                            struct node tt = nxt;
//                            for(int i = 0; i < 3;i++) tt.a[i] = nxt.a[i];
//                            s.insert(tt);
//                        }
//                    }
//                }
//                if(!p1.empty()){
//                    struct node t = p1.front(); p1.pop();
//                    for(int j = 0;j < 3;j++){
//                        struct node nxt = t;
//                        nxt.a[j] -= A[t.dig].a[j];
//                        nxt.dig = t.dig - 1;
//                        p1.push(nxt);
//                        printf("%I64d %I64d %I64d\n",nxt.a[0],nxt.a[1],nxt.a[2]);
//                        if(nxt.dig + 1== n/2 ) {
//                            printf("-------11");
//                            if(s.find(nxt) != s.end()){printf("YES\n");return;}
//                        }
//                    }
//                    if(t.dig < n/2 ) break;
//                }
//            }
//            printf("NO\n"); return;
    else {
            while(!p.empty()){
                struct node t = p.front(); p.pop();
                for(int j = 0;j < 3;j++){
                        struct node nxt = t;
                        nxt.a[j] += A[t.dig].a[j];
                        nxt.dig = t.dig + 1;
                        p.push(nxt);
//                        printf("%I64d %I64d %I64d\n",nxt.a[0],nxt.a[1],nxt.a[2]);
                        if(nxt.dig - 1== n/2 ){
//                            printf("-----");
                            struct node tt = nxt;
                            for(int i = 0; i < 3;i++) tt.a[i] = nxt.a[i];
                            s.insert(tt);
                        }
                }
                if(t.dig > n/2 ) break;
            }
            while(!p1.empty()){
                    struct node t = p1.front(); p1.pop();
                    for(int j = 0;j < 3;j++){
                        struct node nxt = t;
                        nxt.a[j] -= A[t.dig].a[j];
                        nxt.dig = t.dig - 1;
                        p1.push(nxt);
//                        printf("%I64d %I64d %I64d\n",nxt.a[0],nxt.a[1],nxt.a[2]);
                        if(nxt.dig + 1 == n/2 ) {
//                            printf("----11  ");
                            if(s.find(nxt) != s.end()){printf("YES\n");return;}
                        }
                    }
                    if(t.dig < n/2 ) break;
                }
            printf("NO\n"); return;
    }
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        s.clear();
        while(!p.empty()) p.pop();
        while(!p1.empty()) p1.pop();
        scanf("%d",&n);
        scanf("%I64d%I64d%I64d",&st.a[0],&st.a[1],&st.a[2]);
        for(int i = 0;i < n;i++){
            scanf("%I64d%I64d%I64d",&A[i].a[0],&A[i].a[1],&A[i].a[2]);
        }
        bibfs();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

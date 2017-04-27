#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

struct table{
    int con,num;
    bool operator <(const table a) const {
        if(con != a.con) return con<a.con;
        else return num <a.num;
    }
};

set<table> s;

int main()
{
    int n,q,a[100003],l;
    struct table c;
    scanf("%d%d",&n,&q);
    for(int i = 1;i <= n;i++){
        scanf("%d",&l);
        c.num = i;
        c.con = l;
        s.insert(c);
        a[i] = l;
    }
    char s1[4];int t;
    set<table>::iterator it;
    for(int i = 1;i <= q;i++){
        scanf("%s%d",s1,&t);
        c.con = t;c.num = 0;
        if(s1[0] == 'i') {
            it = s.upper_bound(c);
            if(it == s.end()) printf("-1\n");
            else {
                c = *it;
                printf("%d\n",c.num);
                s.erase(it);
            }
        }
        else {
            c.con = a[t];c.num = t;
            s.insert(c);
        }
    }
    return 0;
}

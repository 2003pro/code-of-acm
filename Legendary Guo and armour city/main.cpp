#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 100003;
struct node{
    int l,r,id;
}opera[N];

int n,q;
int tag[N],a[N],tree[N],s[5*N];

bool cmp(node a,node b){
    return a.r < b.r;
}

void update(int pos,int val)
{
		while (pos<=n) //n为总长度
		{
			tree[pos]+=val;
			pos+=pos&-pos;
		}
}

int read(int pos)
{
		int ans=0;
		while (pos>0)
		{
			ans+=tree[pos];
			pos-=pos&-pos;
		}
		return ans;
}


int main()
{
    scanf("%d%d",&n,&q);
    for(int i = 1;i<=n; i++) scanf("%d",&a[i]);
    for(int i = 1;i<=q; i++){scanf("%d%d",&opera[i].l,&opera[i].r); opera[i].id = i;}
    sort(opera+1,opera+q+1,cmp);
    memset(tree,0,sizeof(tree));
    memset(tag,0,sizeof(tag));
    int cnt = 1;
    for(int i = 1;i<=n; i++){
        update(i,1);
        if(tag[a[i]]) update(tag[a[i]],-1);
        tag[a[i]] = i;
        while(cnt <= q&&opera[cnt].r == i){
            s[opera[cnt].id] = read(opera[cnt].r) - read(opera[cnt].l - 1);
            cnt++;
        }
        if(cnt>q) break;
    }
    for(int i = 1;i <= q;i++) printf("%d\n",s[i]);
    return 0;
}

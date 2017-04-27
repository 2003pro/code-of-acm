#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,i,tmp,j,Q,l,r,ans,a[2005][105];
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%d",&tmp);
		a[i][tmp]=1;
		for(j=1;j<=m;++j)a[i][j]+=a[i-1][j];
	}
	scanf("%d",&Q);
	for(i=1;i<=Q;++i){
		scanf("%d%d",&l,&r);
		ans=0;
		for(j=1;j<=m;++j)ans+=(a[r][j]>a[l-1][j]);
		printf("%d\n",ans);
	}
	return 0;
}

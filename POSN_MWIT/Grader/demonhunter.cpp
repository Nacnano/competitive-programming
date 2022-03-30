#include<bits/stdc++.h>
using namespace std;

bool used[15],trans;
int b[15],a[15][15];
int ans=0,cnt=0;
int n,m;
void solve(int lv)
{
	if(lv==m+1)
	{
		ans=max(ans,cnt);
		return;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(used[i]) continue;
		used[i]=1;
		if(!trans) cnt+=a[i][lv];
		else cnt+=a[lv][i]; 
		solve(lv+1);
		used[i]=0;
		if(!trans) cnt-=a[i][lv];
		else cnt-=a[lv][i];
	}
}

int main(){

	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	
	if(n<m) swap(n,m),trans=1;
	solve(1);
	printf("%d",ans);
}

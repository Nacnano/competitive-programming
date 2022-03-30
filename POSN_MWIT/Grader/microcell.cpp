#include<bits/stdc++.h>
using namespace std;

int a[50010];
long long qs[50010];
vector<int> g[50010];

int dfs(int u,int p)
{
	qs[u]=a[u];
	for(auto v:g[u])
	{
		if(v==p) continue;
		qs[u]+=dfs(v,u);
	}
	return qs[u];
}

int main(){
	
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,-1);
	
	int ans=0;
	for(int i=2;i<=n;i++) if(abs(qs[1]-qs[i]-qs[i])<=k) ans++;
	printf("%d",ans);
}

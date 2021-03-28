#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > g[100010];
int dis[100010];

void dfs(int u)
{	
	for(int i=0;i<(int)g[u].size();i++)
	{
		int v=g[u][i].first;
		int w=g[u][i].second;
		
		if(dis[v]!=1e9) continue;
		
		dis[v]=min(dis[v],dis[u]+w);
		dfs(v);	
	}
}


int main(){
	
	int n;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++) dis[i]=1e9;
	
	for(int i=1;i<=n-1;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	
	dis[1]=0;
	dfs(1);
	
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(dis[i]!=1e9) ans=max(ans,dis[i]);
	}
	printf("%d",ans);
}

#include<bits/stdc++.h>
using namespace std;

vector<int> lev[10010];
vector<int> g[100010];
int vis[100010];
int co;

void dfs(int u)
{
	co++;
	vis[u]=1;
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i];
		if(vis[v]==1)
		{
			co=1e9;
			return;
		}
		else if(vis[v]==0)
		{
			dfs(v);
		}
	}
	
	vis[u]=2;
}

main(){
	
	int n,k,t;
	scanf("%d%d%d",&n,&k,&t);
	
	for(int i=1;i<=n;i++)
	{
		int l,p;
		scanf("%d%d",&l,&p);
		lev[l].push_back(i);
		
		while(p--)
		{
			int x;
			scanf("%d",&x);
			g[i].push_back(x);
		}
	}
	
	int ans=-1;
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<lev[i].size();j++)
		{
			int v=lev[i][j];
			
			if(vis[v]==0)
			{
				dfs(v);
			}
		}
		if(co>t)break;
		ans=i;
	}
	printf("%d",ans);
}

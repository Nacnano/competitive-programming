#include<bits/stdc++.h>
using namespace std;
int k,n,m;

int dis[10005];
vector<int> g[10005];

void dfs(int u,int w)
{
	if(w == k) return;
	for(auto v:g[u])
	{
		if(dis[v] > w +1)
		{
			dis[v] = w+1;
			dfs(v,w+1);
		}
	}
}
int main(){
	
	scanf("%d%d%d",&k,&n,&m);
	while(m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);	
	}
	
	for(int i=1;i<=n;i++) dis[i]=INT_MAX;
	
	dis[1]=0;
	dfs(1,0);
	
	for(int i=n;i>=1;i--)
	{
		if(dis[i] != INT_MAX)
		{
			printf("%d",i);
			break;
		}
	}
}

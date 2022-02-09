#include<bits/stdc++.h>
using namespace std;

struct node{
	int v,c,w;
};

int dis[305][2005];
vector<node> g[305];
int main(){
	
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int s,t;
	scanf("%d%d",&s,&t);
	
	for(int i=0;i<m;i++)
	{
		int u,v,c,w;
		scanf("%d%d%d%d",&u,&v,&c,&w);
		g[u].push_back({v,c,w});
		g[v].push_back({u,c,w});
	}
	
	for(int i=0;i<=k;i++) for(int j=0;j<=n;j++) dis[j][i]=INT_MIN;
	
	dis[s][0]=0;
	for(int now=0;now<=k;now++)
		for(int u=1;u<=n;u++)
			for(auto x:g[u]) if(now-x.w>=0) dis[u][now]=max(dis[u][now],dis[x.v][now-x.w]+x.c);
	
	int ans=-1;
	for(int i=0;i<=k;i++) ans=max(ans,dis[t][i]);
	
	if(ans==-1) printf("Impossible");
	else printf("%d",ans);
}

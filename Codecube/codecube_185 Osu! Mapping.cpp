#include<bits/stdc++.h>
using namespace std;

long long dis[10][10010];
bool vis[10][10010];
vector<pair<long long,long long> > g[10010];

int main(){
	
	int n,m,t,x,y;
	scanf("%d%d%d",&n,&m,&t);
	scanf("%d%d",&x,&y);
	while(m--)
	{
		int u,v;
		long long w;
		scanf("%d%d%lld",&u,&v,&w);
		g[u].push_back({v,w});
	}
	
	for(int i=0;i<t;i++) for(int j=1;j<=n;j++) dis[i][j]=1e17;
	
	priority_queue<pair<long long,pair<int,int> > > pq;
	pq.push({0,{1,x}});
	dis[1][x]=0;
	while(!pq.empty())
	{
		long long w=-pq.top().first;
		int ti=pq.top().second.first;
		int u=pq.top().second.second;
		pq.pop();
	
		if(vis[ti][u]) continue;
		vis[ti][u]=1;
	
		for(auto it:g[u])
		{
			int v=it.first;	
			long long add=it.second;
			int nti=(ti+1)%t;
			if(!vis[nti][v] && dis[nti][v] > dis[ti][u]+add)
			{
				dis[nti][v]=dis[ti][u]+add;
				pq.push({-dis[nti][v],{nti,v}});
			}
		}
	}
	if(dis[0][y]==1e17) printf("-1");
	else printf("%lld",dis[0][y]);
}

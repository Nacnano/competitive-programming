#include<bits/stdc++.h>
using namespace std;

long long dis[15][100010];
vector<pair<int,long long> > g[100010];

 int main(){
 	
 	int n,m,q;
 	scanf("%d%d%d",&n,&m,&q);
 	
 	for(int i=1;i<=m;i++)
 	{
 		int u,v;
 		long long w;
 		scanf("%d%d%lld",&u,&v,&w);
 		g[u].push_back({v,w});
 		g[v].push_back({u,w});
	}
	
	priority_queue<pair<long long, pair<int, int> > > pq;
	pq.push({0,{1,q} });
	
	for(int j=0;j<=q;j++) for(int i=1;i<=n;i++) dis[j][i]=INT_MAX;
	dis[q][1]=0;
	
	while(!pq.empty())
	{
		int u=pq.top().second.first;
		int cnt=pq.top().second.second;
		pq.pop();
		
		for(auto tmp: g[u])
		{
			int v=tmp.first;
			long long w=tmp.second;
			if(cnt<q)
			{
				if(dis[cnt+1][v] > dis[cnt][u]+w)
				{
					dis[cnt+1][v]=dis[cnt][u]+w;
					pq.push({-dis[cnt+1][v],{v,cnt+1}});
				}
			}
			else if(cnt==q)
			{
				if(dis[1][v] > dis[q][u])
				{
					dis[1][v]=dis[q][u];
					pq.push({-dis[1][v],{v,1}});
				}
				if(dis[q][v] > dis[q][u]+w)
				{
					dis[q][v]=dis[q][u]+w;
					pq.push({-dis[q][v],{v,q}});
				}
			}
		}

	}
	
	long long ans = INT_MAX;
	for(int i=1;i<=q;i++) ans=min(ans,dis[i][n]);
	printf("%lld",ans);
	
	return 0;
 }

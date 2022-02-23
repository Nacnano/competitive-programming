#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > g[100010];
vector<pair<int,int> > e;
int dis1[100010], dis2[100010];
int main(){
	
	int n,m,s,t,sum;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=0;i<=n;i++) dis1[i]=1e9, dis2[i]=1e9;
	
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		sum+=w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		e.push_back({u,v});
	}
	
	priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
	
	dis1[s]=0;
	pq.push({0,s});
	while(!pq.empty())
	{
		
		int dist=pq.top().first;
		int u=pq.top().second;
		pq.pop();
		
		if(dis1[u]!=dist)continue;
		for(auto it:g[u])
		{
			if(dist+it.second<dis1[it.first])
			{
				dis1[it.first]=dist+it.second;
				pq.push({dis1[it.first],it.first});
			}
		}
	}
	
	dis2[t]=0;
	pq.push({0,t});
	while(!pq.empty())
	{
		int dist=pq.top().first;
		int u=pq.top().second;
		pq.pop();
		if(dis2[u]!=dist)continue;
		for(auto it:g[u])
		{
			if(dist+it.second<dis2[it.first])
			{
				dis2[it.first]=dist+it.second;
				pq.push({dis2[it.first],it.first});
			}
		}
	}
	
//	for(int i=1;i<=n;i++) printf("%d %d\n",dis1[i],dis2[i]);
	
	int mn=1e9;
	for(auto it:e)
	{
		mn=min(mn, dis1[it.first]+dis2[it.second]);
		mn=min(mn, dis1[it.second]+dis2[it.first]);
	}
	printf("%d",sum-mn);
		
}

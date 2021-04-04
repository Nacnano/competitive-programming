#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > g[50010];
vector<int> level[35];
int dis[50010];

int main(){
	
	int n,m,l;
	scanf("%d%d%d",&n,&m,&l);
	int s,t;
	scanf("%d%d",&s,&t);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		level[x].push_back(i);
	}
	
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back({v,w});
	}
	
	priority_queue<pair<int,int> ,vector<pair<int,int> >, greater<pair<int,int> > > pq;
	
	for(int i=1;i<=n;i++) dis[i]=INT_MAX;
	
	dis[s]=0;
	for(int i=0;i<l;i++)
	{
		int tmp[50010];
		bool vis[50010];
		for(int j=1;j<=n;j++)
		{
			tmp[j]= INT_MAX;
			vis[j] = 0;
		}

		for(auto x:level[i])
		{
			if(dis[x]==INT_MAX) continue;
			tmp[x]=dis[x];
			pq.push({tmp[x],x});
		}			
		
		while(!pq.empty())
		{
			int d=pq.top().first;
			int u=pq.top().second;
			pq.pop();
			if(vis[u]) continue;
			vis[u]=1;
			for(auto x: g[u])
			{
				int v=x.first;
				int w=x.second;
				if(tmp[v] > d + w && !vis[v])
				{
					tmp[v]=d+w;
					pq.push({tmp[v],v});
				}
			}
		}
		
		for(int j=1;j<=n;j++) 
		{
			dis[j]=tmp[j];
			
		}
	}
	
	if(dis[t] == INT_MAX) printf("-1");
	else printf("%d",dis[t]);
}

#include<bits/stdc++.h>
using namespace std;

int n,m,x,y,z;
vector<pair<int,int> > g[10005];
int dis1[10005],dis2[10005];
bool final[10005];
int ans=INT_MAX,d1=INT_MAX,d2=INT_MAX;
bool back=0;

void bfs(int dis[10005], int x)
{	
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
	pq.push({dis[x],x});
	
	while(!pq.empty())
	{
		int u=pq.top().second;
		pq.pop();
		for(auto v:g[u])
		{
			int w=v.second;
			if(dis[v.first] > dis[u] + w)
			{
				dis[v.first] = dis[u] + w;
				pq.push({dis[v.first],v.first});
			}
		}
	}
}


int main(){
	
	scanf("%d%d",&n,&m);
	scanf("%d%d%d",&x,&y,&z);
	
	for(int i=0;i<=n;i++)
	{
		dis1[i]=INT_MAX;
		dis2[i]=INT_MAX;
		final[i]=0;
	}
	
	while(m--)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	
	dis1[x]=0;
	bfs(dis1,x);
	
	dis2[y]=0;
	bfs(dis2,y);
	
	for(int i=0;i<n;i++)
	{
		if(dis1[i] <= z)
		{
			if(dis2[i] < d2)
			{
				d2=dis2[i];
				d1=dis1[i];
				ans=i;
			}
			
			if(dis2[i] == d2)
			{
				if(i<ans)
				{
					ans=i;
					d1=dis1[i];
				}
			}
		}
	}
	printf("%d %d %d",ans,d1,d2);
}

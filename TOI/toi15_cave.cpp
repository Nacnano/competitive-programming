#include<bits/stdc++.h>
using namespace std;

vector<pair<long long,int> > g[2010];
priority_queue< pair<pair<long long,int>,int>, vector<pair<pair<long long,int>,int> >, greater<pair<pair<long long,int>,int> > > pq;
set<pair<long long,int> > dist[2010];

int main(){
	
	int n,p,u,e;
	scanf("%d%d%d%d",&n,&p,&u,&e);
	for(int i=0;i<e;i++)
	{
		int q,r,t;
		scanf("%d%d%d",&q,&r,&t);
		g[q].push_back({t,r});
	}
	dist[p].insert({0,0});
	pq.push({{0,0},p});
	
	while(!pq.empty())
	{
	
		long long d=pq.top().first.first;
		int cnt=pq.top().first.second;
		int now=pq.top().second;
		pq.pop();

		for(auto v:g[now])
		{
			bool chk=1;
			
			for(auto e:dist[v.second])
			{
				if(e.first<d+v.first && e.second<cnt+1)
				{
					chk=0;
					break;
				}
			}
			
			if(chk)
			{
				pq.push({{d+v.first,cnt+1},v.second});
				dist[v.second].insert({d+v.first,cnt+1});
			}
		}	
	}
	
	int l;
	scanf("%d",&l);
	
	while(l--)
	{
		long long ans=1e18;
		int h;
		scanf("%d",&h);
		
		for(auto u2 : dist[u])
		ans=min(ans,u2.first+u2.second*h-h);
		
		printf("%lld ",ans);
	}
	
}

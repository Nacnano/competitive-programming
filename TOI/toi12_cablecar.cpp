#include<bits/stdc++.h>
using namespace std;

priority_queue<pair<int,pair<int,int> > > pq;
int p[2510];

int _find(int x)
{
	if(p[x]==x) return x;
	else return p[x]=_find(p[x]);
}

void _union(int x,int y)
{
	p[_find(x)]=_find(y);
	return;
}

main(){
	
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		pq.push(make_pair(w,make_pair(u,v)));
	}
	
	int st,ed,pe;
	scanf("%d%d%d",&st,&ed,&pe);
	
	for(int i=1;i<=n;i++)
	{
		p[i]=i;
	}
	
	int mn=1e9;
	while(!pq.empty())
	{
		int w=pq.top().first;
		int u=pq.top().second.first;
		int v=pq.top().second.second;
		pq.pop();
		if(_find(st)!=_find(ed))
		{
			_union(u,v);
			mn=min(mn,w);
		}
	}
	
	double ans=(double)pe/(mn-1);
	printf("%.0f",ceil(ans));
	
}
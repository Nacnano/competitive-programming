#include<bits/stdc++.h>
using namespace std;

int p[200010];

int _find(int x)
{
	if(p[x]==x) return x;
	else return p[x]=_find(p[x]);
}

void _union(int x,int y)
{
	int px=_find(x);
	int py=_find(y);
	
	p[px]=py;
}
vector<pair<int,int> > g[200010];
vector<pair<int, pair<int,int>>> l;

int main(){
	
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		l.push_back({w,{u,v}});
	}
	
	sort(l.begin(),l.end());
	
	for(int i=1;i<=n;i++) p[i]=i;
	
	long long ans=0;
	int mst=0;
	for(int i=m;i>=0 && mst<n;i--)
	{
		int w=l[i].first;
		int u=l[i].second.first;
		int v=l[i].second.second;
		
		int pu=_find(u);
		int pv=_find(v);
		
		if(pu!=pv)
		{
			ans+=w-1;
			_union(u,v);
			mst++;
		}
	}
	
	printf("%lld",ans);
	
	
}

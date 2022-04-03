#include<bits/stdc++.h>
using namespace std;

int p[3010];
int dp[1000010];
vector<pair<int,int> > e;
int co;

int mm[3010][3010];

int _find(int x)
{
	if(p[x]==x) return x;
	else
	return p[x]=_find(p[x]);
}

void _union(int x,int y)
{
	int px=_find(x);
	int py=_find(y);
	p[px]=py;
	return;
}
bool comp(pair<int,int> &lhs, pair<int, int> &rhs){
	return mm[lhs.first][lhs.second] < mm[rhs.first][rhs.second];	
}
int main(){
	
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=0;i<=n;i++) p[i]=i;
	
	for(int i=0;i<m;i++)
	{
		int u,v,l,r;
		scanf("%d%d%d%d",&u,&v,&l,&r);
		
		if(r==1)
		{
			_union(u,v);
			mm[u][v]=0;
		}
		else
		{
			e.push_back(make_pair(u,v));
			mm[u][v]=l;
		}
		
		
	}
	
	for(int i=0;i<=1000005;i++) dp[i]=INT_MAX;
	
	int pack;
	scanf("%d",&pack);
	while(pack--)
	{
		int l,c;
		scanf("%d%d",&l,&c);
		dp[l]=min(dp[l],c);
	}
	
	for(int i=1000000;i>=0;i--)
	{
		dp[i]=min(dp[i+1],dp[i]);
	}
	
	dp[0]=0;
	sort(e.begin(), e.end(), comp);
	long long ans=0;
	for(int i=0;i<(int)e.size();i++)
	{
		int u=e[i].first;
		int v=e[i].second;
		
		if(_find(v)!=_find(u))
		{
			_union(u,v);
			ans+=dp[mm[u][v]];
		}
	}
	
	printf("%lld",ans);
	
}
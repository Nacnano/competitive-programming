#include<bits/stdc++.h>
using namespace std;

map<vector<pair<int,int> >, int> mm;
vector<pair<int,int> > g;

int main(){
	
	int t,q;
	scanf("%d%d",&t,&q);
	
	while(t--)
	{
		int n;
		scanf("%d",&n);
		n--;
		while(n--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			g.push_back({min(u,v),max(u,v)});
			
		}
		sort(g.begin(),g.end());
		mm[g]++;
		g.clear();
	}
	
	while(q--)
	{
		int m;
		scanf("%d",&m);
		m--;
		while(m--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			g.push_back({min(u,v),max(u,v)});
		}
		sort(g.begin(),g.end());
		printf("%d\n",mm[g]);
		g.clear();
	}
	
}

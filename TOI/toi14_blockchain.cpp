#include<bits/stdc++.h>
using namespace std;

map<vector<pair<int,int> >,int > mm;

int main(){
	
	int t,q;
	scanf("%d%d",&t,&q);
	while(t--)
	{
		vector<pair<int,int> > g;
		int n;
		scanf("%d",&n);
		n--;
		while(n--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			if(v<u) swap(u,v);
			g.push_back({u,v}); 
		}
		sort(g.begin(),g.end());
		mm[g]++;
	}
	
	while(q--)
	{
		vector<pair<int,int> > g;
		int n;
		scanf("%d",&n);
		n--;
		while(n--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			if(v<u) swap(u,v);
			g.push_back({u,v}); 
		}
		sort(g.begin(),g.end());
		printf("%d\n",mm[g]);
	}
}


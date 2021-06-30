#include<bits/stdc++.h>
using namespace std;

vector<int> g[1000010];
int dis[510][510];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			if(i!=j) dis[i][j]=1e7;
	
	for(int i=1;i<=m;i++)
	{
		int s;
		scanf("%d",&s);
		while(s--)
		{
			int u;
			scanf("%d",&u);
			for(auto v:g[u])
			{
				if(i==v) continue;
				dis[i][v]=1;
				dis[v][i]=1;
			}
			g[u].push_back(i);
		}
	}
	
	for(int k=1;k<=m;k++)
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		
		int ans=1e7;
		for(auto u:g[a])
			for(auto v:g[b])
				ans=min(ans,dis[u][v]);
				
		if(ans==1e7) printf("impossible\n");
		else printf("%d\n",ans);
	}
	
	return 0;
}

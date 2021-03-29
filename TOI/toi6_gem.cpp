#include<bits/stdc++.h>
using namespace std;

vector<int> g1[400010];
vector<int> g2[400010];
int vis[400010];

set<int> ss;
stack<int> stk;

void dfs1(int u)
{
	if(vis[u]==1) return;
	vis[u]=1;
	for(int v: g1[u]) dfs1(v);
	stk.push(u);
}

void dfs2(int u)
{
	if(vis[u]==1) return;
	vis[u]=1;
	ss.insert(u);
	for(int v: g2[u]) dfs2(v);
}

int main(){
	
	int t=5;
	
	while(t--)
	{
		int n,m;
		scanf("%d",&n);
		scanf("%d",&m);
		
		for(int i=1;i<=2*m;i++) g1[i].clear(), g2[i].clear(), vis[i]=0;
		
		for(int i=1;i<=n;i++)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			
			g1[u+m].push_back(v);
			g1[v+m].push_back(u);
			g2[v].push_back(u+m);
			g2[u].push_back(v+m);
		}
		
		for(int i=1;i<=m/2;i++)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			
			g1[u].push_back(v+m);
			g1[v].push_back(u+m);
			g2[v+m].push_back(u);
			g2[u+m].push_back(v);
		}
		
		for(int i=1;i<=2*m;i++)
		{
			if(vis[i]==1) continue;
			dfs1(i);
		}
		
		for(int i=1;i<=2*m;i++) vis[i]=0;
		bool con=1;
		while(!stk.empty())
		{
			int u=stk.top();
			stk.pop();
			if(vis[u]==1) continue;
			ss.clear();
			dfs2(u);
				
			//printf("SCC ");
			for(int x:ss)
			{
			//	printf("%d ",x);
				
				if(x>m) continue;
				
				if(ss.find(x+m)!=ss.end()) con=0;	
			}
			//printf("\n");
		}
		if(con) printf("Y");
		else printf("N");
	}
}


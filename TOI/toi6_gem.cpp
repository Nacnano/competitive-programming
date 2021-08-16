#include<bits/stdc++.h>
using namespace std;

vector<int> g[400010];
bool vis[400010];
int u1[200010],v1[200010],u2[200010],v2[200010];


set<int> ss;
stack<int> stk;

void dfs1(int u)
{
	if(vis[u]==1) return;
	vis[u]=1;
	for(int v: g[u]) dfs1(v);
	stk.push(u);
}

void dfs2(int u)
{
	if(vis[u]==1) return;
	vis[u]=1;
	ss.insert(u);
	for(int v: g[u]) dfs2(v);
}

int main(){
	
	int t=5;
	
	while(t--)
	{
		int n,m;
		scanf("%d",&n);
		scanf("%d",&m);
		
		
		
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d",&u1[i],&v1[i]);
			
			g[u1[i]+m].push_back(v1[i]);
			g[v1[i]+m].push_back(u1[i]);
		}
		
		for(int i=1;i<=m/2;i++)
		{
			scanf("%d %d",&u2[i],&v2[i]);
			
			g[u2[i]].push_back(v2[i]+m);
			g[v2[i]].push_back(u2[i]+m);
		}
		
		for(int i=1;i<=2*m;i++)
		{
			if(vis[i]==1) continue;
			dfs1(i);
		}
		
		for(int i=1;i<=2*m;i++) g[i].clear(), g[i].clear(), vis[i]=0;
		for(int i=1;i<=2*m;i++) vis[i]=0;
		
		//transpose	
		for(int i=1;i<=n;i++)
		{
			g[v1[i]].push_back(u1[i]+m);
			g[u1[i]].push_back(v1[i]+m);
		}
		
		for(int i=1;i<=m/2;i++)
		{
			g[v2[i]+m].push_back(u2[i]);
			g[u2[i]+m].push_back(v2[i]);
		}
		
		bool con=1;
		while(!stk.empty())
		{
			int u=stk.top();
			stk.pop();
			if(vis[u]==1) continue;
			ss.clear();
			dfs2(u);

			for(int x:ss)
			{	
				if(x>m) continue;	
				if(ss.find(x+m)!=ss.end()) con=0;	
			}
		}
		if(con) printf("Y");
		else printf("N");
		
		for(int i=1;i<=2*m;i++) g[i].clear(), g[i].clear(), vis[i]=0;
	}
}

#include<bits/stdc++.h>
using namespace std;

int ans;
vector<int> g[100010];
int t[100010];
int k[100010];
int vis[100010];
int cnt[100010];
int chk[100010];
int tar[100100][100];
vector<int> node[100010];

void dfs(int u)
{
	if(vis[u]) return;
	vis[u]=1;
	
	for(auto tmp:node[u])
	{
		chk[tmp]++;
	}
	for(auto tmp:g[u])
	{
		if(chk[tmp]==tar[tmp])
		{
			ans++;
			dfs(tmp);
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(NULL); cin.tie(NULL);
	
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=0;i<m;i++)
	{
		vector<int> req;
		scanf("%d",&k[i]);
		for(int j=0;j<k[i];j++)
		{
			int x;
			scanf("%d",&x);
			req.push_back(x);
		}
		
		scanf("%d",&t[i]);
		for(auto tmp:req)
		{
			g[tmp].push_back(t);
			node[tmp].push_back(i);
		}
	}
	
	dfs(1);
	printf("%d",ans);
	
	return 0;
}

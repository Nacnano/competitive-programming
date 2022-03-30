#include<bits/stdc++.h>
using namespace std;

vector<int> g[200005];
int cnt[200005];

void dfs(int u)
{
	int sub=0;
	for(auto v: g[u])
	{
		dfs(v);
		sub+=(cnt[v]+1);
	}
	cnt[u]=sub;
}

int main(){
	
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		g[x].push_back(i);
	}

	dfs(1);
	for(int i=1;i<=n;i++) printf("%d ",cnt[i]);
}

#include<bits/stdc++.h>
using namespace std;

const int mxn=500000;
bool ro[mxn+5];
bool vis[mxn+5];
vector<int> wa[mxn+5];
int n,m,k;
int mxvis;

void dfs(int u)
{
	if(vis[u]==1 || u>n) return;
	vis[u]=1;

	mxvis=max(mxvis,u);
	if(ro[u]==0) dfs(u+1);

	for(auto v: wa[u])
	{
		if(vis[v]==0) dfs(v);
	}
	return;
}

int main(){


	scanf("%d%d%d",&n,&m,&k);

	while(m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		wa[a].push_back(b);
	}

	while(k--)
	{
		int r;
		scanf("%d",&r);
		ro[r]=1;
	}

	dfs(1);

	if(vis[n]==1) printf("1");
	else
	{
		printf("0 %d",mxvis);

	}
}

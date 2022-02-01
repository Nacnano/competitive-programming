#include<bits/stdc++.h>
using namespace std;

vector<int> leaf;
int par[1005], ti[1005], w[1005];
vector<int> dif;

void dfs(int u)
{
	if(u==1) return;
	
	ti[par[u]]=max(ti[par[u]],ti[u]+w[u]);
	dfs(par[u]);
}

int main(){

	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		
		if(a==0 && c==0)
		{
			leaf.push_back(i);
		}
		if(a)
		{
			par[a]=i;
			w[a]=b;
		}
		if(c)
		{
			par[c]=i;
			w[c]=d;
		}
		
		dif.push_back(abs(b-d));
	}
	
	sort(dif.begin(),dif.end());
	
	int minus=0;
	for(int i=1;i<=k;i++)
	{
		minus+=dif[n-i];	
	}
	
	for(auto u: leaf)
	{
		dfs(u);
		// ti[par[u]]=max(ti[par[u]],ti[u]+w[u]);
	}
	printf("%d\n",ti[1]);
	printf("%d",ti[1]-minus);
}

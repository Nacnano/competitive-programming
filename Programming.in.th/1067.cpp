#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int a[105][105];
int ans;

void dfs(int x,int y, pair<int,int> prev,vector<vector<int>> vis)
{	

	if(x<=0 || x>n || y<=0 || y>m)
	{ 
		ans = a[prev.second][prev.first];
		return;
	}
	if(vis[y][x])
	{
		ans = 0;
		return;
	}
	vis[y][x]=1;
	
	if(a[y][x] == 1) dfs(x , y-1, {x,y},vis);
	else if(a[y][x] == 2) dfs(x+1, y, {x,y},vis);
	else if(a[y][x] == 3) dfs(x, y+1, {x,y},vis);
	else if(a[y][x] == 4) dfs(x-1, y, {x,y},vis);
}

int main(){

	scanf("%d%d%d",&n,&m,&k);
	
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	
	while(k--)
	{
		vector< vector<int> > vis (105,vector<int> (105,0));
		
		int x,y;
		scanf("%d%d",&x,&y);
		dfs(x,y, {x,y},vis);
		
		if(ans==0) printf("NO\n");
		else if(ans==1) printf("N\n");
		else if(ans==2) printf("E\n");
		else if(ans==3) printf("S\n");
		else if(ans==4) printf("W\n");
	}
}	

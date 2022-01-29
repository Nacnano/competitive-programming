#include<bits/stdc++.h>
using namespace std;

int n;
string s[35];
int ans;
int cnt;
int vis[35][35];
int d[5][3]= {{0,1},{0,-1},{1,0},{-1,0}};

void dfs(int x,int y)
{
	if(vis[y][x]) return;
	if(!vis[y][x]) cnt++;
	vis[y][x]=1;
//	printf("%d %d %d \n",x,y,cnt);
	for(int i=0;i<4;i++)
	{
		int nx=x+d[i][0];
		int ny=y+d[i][1];
		
		if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
		if(s[ny][nx]!=s[y][x])
		{
			dfs(nx,ny);
		}
	}
	
	return;
}

int main(){
	ios_base::sync_with_stdio(NULL); cin.tie(NULL);
	
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> s[i];
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(!vis[i][j])
			{
				cnt=0;
				dfs(i,j);
				ans=max(ans,cnt);
			}
		}
	}
	printf("%d",ans);
	
	
	return 0;
}

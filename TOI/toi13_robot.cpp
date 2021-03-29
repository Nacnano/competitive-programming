#include<bits/stdc++.h>
using namespace std;

char s[2010][2010];
int d[2010][2010];
bool vis[2010][2010];
queue <pair<int,int>> q;

int ar[4][3]={{1,0},{-1,0},{0,1},{0,-1}};


int main(){
	
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",&s[i]);
		for(int j=0;j<m;j++)
		{
			
//			if(s[i][j]=='W') d[i+1][j+1]=2;
//			else m[i+1][j+1]=1;
			if(s[i][j]=='X') q.push({j+1,i+1});
		}
	}
	
	int co=0,sum=0;
	
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		if(vis[y][x]==1) continue;
		
		vis[y][x]=1;
		
		if(s[y-1][x-1]=='A')
		{
			co++;
			sum+=2*d[y][x];
		}
		
		for(int i=0;i<4;i++)
		{
			int nx=x+ar[i][0];
			int ny=y+ar[i][1];

			if(nx<1 || nx>m || ny<1 || ny>n) continue;
			if(vis[ny][nx]==1 || s[ny-1][nx-1]=='W') continue;
			if(s[ny-1][nx-1]=='X') continue;
			
			
			if(d[ny][nx]==0) d[ny][nx]=d[y][x]+1;
			else d[ny][nx]=min(d[y][x]+1,d[ny][nx]);
			
			q.push({nx,ny});
		}
	}
	
	printf("%d %d",co,sum);
	
	
}

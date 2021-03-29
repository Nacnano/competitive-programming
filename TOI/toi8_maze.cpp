#include<bits/stdc++.h>
using namespace std;

int maze[160][160];
int dist[160][160];
int bombed[160][160];
int col[160][160];
int d[5][5]={{1,0},{-1,0},{0,1},{0,-1}};


int main(){
	
	int m,n,rs,cs,re,ce;
	scanf("%d%d",&m,&n);
	scanf("%d%d",&rs,&cs);
	scanf("%d%d",&re,&ce);
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&maze[i][j]);
		}
	}
	
	queue<pair<int,int> > q;
	dist[rs][cs]=1;
	dist[re][ce]=1;
	col[rs][cs]=2;
	col[re][ce]=3;
	
	q.push({cs,rs});
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		for(int i=0;i<4;i++)
		{
			int nx=x+d[i][0];
			int ny=y+d[i][1];
			
			if(nx>=n+1 || nx<=0 || ny>=m+1 || ny<=0) continue;
			
			if(maze[ny][nx]==1 && col[ny][nx]==0)
			{
				dist[ny][nx]=dist[y][x]+1;
				col[ny][nx]=2;
				q.push({nx,ny});
			}
		}
		q.pop();
	}
	
	
	int ans=1E9;
	int total=0;
	
	q.push({ce,re});
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		
		for(int i=0;i<4;i++)
		{
			int nx=x+d[i][0];
			int ny=y+d[i][1];
			
			if(nx>=n+1 || nx<=0 || ny>=m+1 || ny<=0) continue;
			
			if(maze[ny][nx]==1 && col[ny][nx]==0)
			{
				dist[ny][nx]=dist[y][x]+1;
				col[ny][nx]=3;
				q.push({nx,ny});
			}
			
			if(maze[ny][nx]==0)
			{
				if(bombed[ny][nx]) continue;
				
				int nnx,nny;
				int can=0;
				for(int j=0;j<4;j++)
				{
					nnx=nx+d[j][0];
					nny=ny+d[j][1];
					
					if(nnx==x && nny==y) continue;
					
					if(dist[nny][nnx]>0 && col[nny][nnx]==2)
					{
		//				printf("%d %d to %d %d\n",ny,nx,nnx,nny);
						ans=min(ans,dist[nny][nnx]+dist[y][x]+1);
						can=1;
					}	
				}
				if(can) total++;
			}
			bombed[ny][nx]=1;
		}
		q.pop();
	}
	
//	printf("\n");
//	for(int i=1;i<=m;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			printf("%d ",dist[i][j]);
//		}
//		printf("\n");
//	}
//	
	printf("%d\n%d",total,ans);
}

#include<bits/stdc++.h>
using namespace std;

int dis[10][10];
bool vis[10][10];

int d[10][3]={{2,1}, {-2,1},{2,-1}, {-2,-1}, {1,2}, {-1,2}, {1,-2},{-1,-2} };


int main(){
	
	int n,m;
	int x1,y1,x2,y2;
	scanf("%d%d%d%d%d%d",&n,&m,&x1,&y1,&x2,&y2);

	queue<pair<int,int > > q;
	
	q.push({x1,y1});
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		for(int i=0;i<8;i++)
		{
			int nx=x+d[i][0];
			int ny=y+d[i][1];
			
			if(nx<=0 || ny<=0 || nx>n || ny>n) continue;
			
			if(!dis[ny][nx])
			{
				dis[ny][nx]=dis[y][x]+1;
				q.push({nx,ny});
			}
		}
	} 
	
	if(dis[y2][x2]>m) printf("YIKES");
	else printf("CHECK");
	
	
}


#include<bits/stdc++.h>
using namespace std;

char a[2003][2003];

int d[10][3]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

main(){
	
	int n,m;
	scanf("%d%d",&n,&m);

	for(int i=0;i<n;i++)
	scanf("%s",a[i]);
	
	queue<pair<int,int> > q; 
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]=='1')
			{
				a[i][j]='0';
				ans++;
				q.push(make_pair(i,j));
				
				while(!q.empty())
				{
					int x=q.front().second;
					int y=q.front().first;
					q.pop();
					for(int k=0;k<8;k++)
					{
						int nx=x+d[k][0];
						int ny=y+d[k][1];
						
						if(a[ny][nx]=='1')
						{
							q.push(make_pair(ny,nx));
							a[ny][nx]='0';
						}
						
					}
				}
			}
		}
	}
	printf("%d",ans);
}
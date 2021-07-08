#include<bits/stdc++.h>
using namespace std;

bool have[1050][1050];

int main(){
	
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		have[y][x]=1;
	}
	
	while(m--)
	{
		int x,y,r;
		scanf("%d%d%d",&x,&y,&r);
		int cnt=0;
		for(int i=x-r;i<=x+r;i++)
		{
			for(int j=y-r;j<=y+r;j++)
			{
				if(i<0 || j<0) continue;
				if(have[j][i])
				{
					have[j][i]=0;
					cnt++;
				}
			}
		}
		printf("%d\n",cnt);
	}
}

#include<bits/stdc++.h>
using namespace std;

int tree[510][510];
int qsum[510][510];

int sqsum(int a,int b,int x,int y)
{
	return qsum[y][x]-qsum[y][a-1]-qsum[b-1][x]+qsum[b-1][a-1];
}

int main(){
	
	int q=2;
	
	while(q--)
	{
		int m,n,t;
		scanf("%d %d",&m,&n);
		scanf("%d",&t);
		while(t--)
		{
			int r,c;
			scanf("%d %d",&r,&c);
			tree[r+1][c+1]=1;
		}
		
		for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) qsum[i][j]=qsum[i-1][j]+qsum[i][j-1]-qsum[i-1][j-1]+tree[i][j];
	
		int ans=-1;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int mn=min(m-i+1,n-j+1);
				for(int k=0;k<=mn;k++)
				{
					if(i+k>m || j+k>n) break;
					
					if(sqsum(j,i,j+k,i+k)-sqsum(j+1,i+1,j+k-1,i+k-1)==0)	
						ans=max(ans,k);
				}
			}
		}	
		printf("%d\n",ans+1);
		
		for(int i=0;i<=m;i++) for(int j=0;j<=n;j++) tree[i][j]=0,qsum[i][j]=0;
	}
}

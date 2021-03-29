#include<bits/stdc++.h>
using namespace std;

char x[1010],y[1010],z[2010];

int main(){
		
	scanf("%s",x);
	scanf("%s",y);
	int m=strlen(x), n=strlen(y);
	
	int k;
	scanf("%d",&k);
	
	while(k--)
	{
		scanf("%s",z);		
		
		bool dp[1010][1010];
		dp[0][0]=1;
		for(int i=0;i<=m;i++)
		{
			for(int j=0;j<=n;j++)
			{
				if(i==0 && j==0) continue;
				else if(i==0)
				{
					if(dp[i][j-1] && y[j-1]==z[i+j-1])
					dp[i][j]=1;
					continue;
				}
				else if(j==0)
				{
					if(dp[i-1][j] && x[i-1]==z[i+j-1])
					dp[i][j]=1;
					continue;
				}
				
				if(dp[i-1][j] && x[i-1]==z[i+j-1])
				{
					dp[i][j]=1;	
					continue;
				}
				if(dp[i][j-1] && y[j-1]==z[i+j-1])
				{
					dp[i][j]=1;
					continue;
				}
				
				dp[i][j]=0;
			}
		}
		if(dp[m][n]) printf("Yes\n");
		else printf("No\n");
	}
}

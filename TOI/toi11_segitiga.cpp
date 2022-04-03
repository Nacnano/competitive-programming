#include<bits/stdc++.h>
using namespace std;
int n;
char s[260];
bool dp[260][260][3];
int main(){
	int q=20;
	while(q--)
	{
		int n;
		scanf("%d",&n);
		
		scanf("%s",s);
		
		for(int l=1;l<=n;l++)
		{
			for(int i=0,j=l-1;j<n;j++,i++)
			{
				for(int k=i;k<=j;k++)
				{
					if(l==1)dp[i][j][s[k]-'0']=1;
					
					else
					{
						if(dp[i][k][0] && dp[k+1][j][0]) dp[i][j][2]=1;
						if(dp[i][k][0] && dp[k+1][j][1]) dp[i][j][1]=1;
						if(dp[i][k][0] && dp[k+1][j][2]) dp[i][j][0]=1;
						if(dp[i][k][1] && dp[k+1][j][0]) dp[i][j][2]=1;
						if(dp[i][k][1] && dp[k+1][j][1]) dp[i][j][1]=1;
						if(dp[i][k][1] && dp[k+1][j][2]) dp[i][j][1]=1;
						if(dp[i][k][2] && dp[k+1][j][0]) dp[i][j][1]=1;
						if(dp[i][k][2] && dp[k+1][j][1]) dp[i][j][2]=1;
						if(dp[i][k][2] && dp[k+1][j][2]) dp[i][j][1]=1;
					}
				}
			}
		}
		if(dp[0][n-1][0]) printf("yes\n");
		else printf("no\n");
		
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				dp[i][j][0]=0;
				dp[i][j][1]=0;
				dp[i][j][2]=0;
			}
		}
	}
	return 0;
}
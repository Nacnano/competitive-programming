#include<bits/stdc++.h>
using namespace std;

int t[1010];
int dp[1010][3010];
int main(){
	ios_base::sync_with_stdio(NULL), cin.tie(NULL);
	
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&t[i]);
	for(int i=1;i<=n;i++) dp[i][0]=1e9;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3000;j++)
		{
			if(t[i]==j) dp[i][j]=dp[i-1][j-1];
			else dp[i][j]=dp[i-1][j-1]+1;
			dp[i][j]=min(dp[i][j],dp[i][j-1]);
		}
	}
	printf("%d",dp[n][3000]);
}

#include<bits/stdc++.h>
using namespace std;

int a[2010];
int dp[2010][2010];

int main(){
	
	int n;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(int i=1;i<=n;i++)
	{
		dp[0][i]=max(dp[0][i-1],dp[2][i-1]-a[i]);
		
		for(int j=1;j<=i;j++)
		{
			dp[j][i]=max(dp[j+2][i-1]-a[i],dp[j-1][i-1]+a[i]);
		}
	}
	
	printf("%d",dp[0][n]);
}

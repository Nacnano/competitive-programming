#include<bits/stdc++.h>
using namespace std;

long long dp[1510][1510];
bool obs[1510][1510];

int main(){
	
	int m,n,o;
	
	scanf("%d %d",&m,&n);
	scanf("%d",&o);
	
	while(o--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		obs[a][b]=1;
	}
	
	dp[1][1]=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==1 && j==1) continue;
			if(obs[i][j]==1) continue;
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	
	printf("%lld",dp[m][n]);
}

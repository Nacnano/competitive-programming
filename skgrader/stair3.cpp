#include<bits/stdc++.h>
using namespace std;

long long dp[60];
long long dp2[60];
int main(){

	int i, n;
	scanf("%d",&n);
	
	dp[0]=1;
	dp[1]=1;
	dp[2]=2;
	
	for(i=3;i<=55;i++) dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
	
	dp2[0]=2;
	dp2[1]=dp2[0]+dp[2];
	dp2[2]=dp2[1]+dp2[0]+dp[3];
	dp2[3]=dp2[2]+dp2[1]+dp2[0]+dp[4];
	
	for(i=4;i<55;i++) dp2[i]=dp2[i-1]+dp2[i-2]+dp2[i-3]+dp[i+1];

	for(int i=0;i<=n;i++) printf("%d\n",dp2[i]);
	printf("%lld",dp2[n-1]+dp[n]);
}

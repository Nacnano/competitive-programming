#include<bits/stdc++.h>
using namespace std;

int dp[100010];
int main(){
	
	int n,k;
	scanf("%d%d",&n,&k);
	dp[0]=1;
	
	int tmp=0;
	for(int i=1;i<=k;i++)
	{
		dp[i]+=dp[i-1]+tmp;
		tmp+=dp[i-1];
		dp[i]+=2009, tmp+=2009;
		dp[i]%=2009, tmp%=2009;
	}
	
	for(int i=k+1;i<=n;i++)
	{
		tmp+=dp[i-1];
		tmp-=dp[i-k-1];
		dp[i]=tmp;
		dp[i]+=2009, tmp+=2009;
		dp[i]%=2009, tmp%=2009;
	}
	printf("%d ",dp[n]);
}

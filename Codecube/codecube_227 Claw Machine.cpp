#include<bits/stdc++.h>
using namespace std;

const long long mod=1e9+7;
long long a[100010];
long long dp[100010][110];

int main(){
	
	long long n,q;
	scanf("%d%d",&n,&q);
	
	dp[0][0]=1;
	for(long long i=1;i<=n;i++)
	{
		long long x;
		scanf("%lld",&x);
		for(long long j=0;j<=100;j++) dp[i][j]+=dp[i-1][j];
		for(long long j=0;j<=100;j++)
		{
			if(j-x>=0) dp[i][j]+=dp[i-1][j-x];
			dp[i][j]%=mod;
		}
	}
	
	while(q--)
	{
		long long l,r,k;
		scanf("%lld%lld%lld",&l,&r,&k);
		long long dp2[110];
		for(long long i=0;i<=k;i++)
		{
			dp2[i]=dp[r][i];
			for(long long j=1;j<=i;j++)
			{
				dp2[i]-=(dp2[i-j]*dp[l-1][j]%mod);
				dp2[i]=(dp2[i]+mod)%mod;
			}
		}
		printf("%lld\n",dp2[k]);
	}
	return 0;
}

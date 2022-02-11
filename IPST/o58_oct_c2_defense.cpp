#include<bits/stdc++.h>
using namespace std;

long long a[3010], dp[3010][3010], dp2[3010], ans=1e18;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(0);
	
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=0;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=1e18;
	for(int i=0;i<=n;i++) dp2[i]=1e18;
	for(int i=1;i<=k;i++) for(int j=i+1;j<=k;j++) dp[i][j]=a[i]+a[j];
	
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j>max(i,k);j--)
		{
			if(j-i>=k) continue;
			dp2[i]=min(dp2[i], dp[j-k][i]);
			dp[i][j]=min(dp[i][j],dp2[i]+a[j]);
		}
	}
	
	for(int i=n-k+1;i<=n;i++) for(int j=i+1;j<=n;j++) ans=min(ans,dp[i][j]);
	printf("%lld",ans);
	return 0;	
}

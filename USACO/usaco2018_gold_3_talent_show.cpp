#include<bits/stdc++.h>
using namespace std;

int w[255],t[255];
int dp[260005];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	freopen("talent.in","r",stdin);
	freopen("talent.out","w",stdout);
	
	int n,W;
	scanf("%d%d",&n,&W);
	for(int i=1;i<=n;i++) scanf("%d%d",&w[i],&t[i]);
	
	for(int i=1;i<=250000;i++) dp[i]=1e9;
	
	for(int j=1;j<=n;j++)
		for(int i=1000*250;i>=0;i--)
			dp[i+t[j]]=min(dp[i+t[j]],dp[i]+w[j]);
	
	double ans=0;
	for(int i=1;i<=250000;i++)
	{
		if(dp[i]==1e9) continue;
		if(dp[i]>=W) ans=max(ans,i/(double)dp[i]);
	}
	printf("%ld",int(1000*ans));
}

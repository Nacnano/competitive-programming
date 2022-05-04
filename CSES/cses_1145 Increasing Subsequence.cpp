#include<bits/stdc++.h>
using namespace std;
const int mxn=2e5+5;

long long dp[mxn], a[mxn], ans=0;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i], dp[i]=1e18;
	dp[0]=-1e18, dp[n]=1e18;
	for(int i=0;i<n;i++)
	{
		int it=upper_bound(dp,dp+n,a[i])-dp;
		if(dp[it-1]<a[i] && a[i]<dp[it]) dp[it]=a[i];
	}
	for(int i=0;i<=n;i++) if(dp[i]!=1e18) ans=i;
	cout << ans;
}

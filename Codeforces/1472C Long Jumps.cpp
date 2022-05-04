#include<bits/stdc++.h>
using namespace std;
const int mxn=2e5+5;
	
long long dp[mxn], a;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			cin >> a;
			if(i+a>n) ans=max(ans,dp[i]+a);
			else dp[i+a]=max(dp[i+a],dp[i]+a);
		}
		cout << ans << "\n";
		for(int i=0;i<=n;i++) dp[i]=0;
	}
}

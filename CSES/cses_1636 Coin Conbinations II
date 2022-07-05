#include<bits/stdc++.h>
using namespace std;
const int mxn = 105;
const int  mxx = 1000010;
const int p =1e9+7;

int dp[mxx];
int coin[mxn];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

	int n, x;
	cin >> n >> x;
	for(int i=1;i<=n;i++) cin >> coin[i];
	sort(coin, coin+n);

	dp[0]=1;
	for(int j=1;j<=n;j++){
		for(int i=1;i<=x;i++){
			if(i>=coin[j]) dp[i] += dp[i-coin[j]];
			dp[i] %= p;
		}
	}
	cout << dp[x];

	return 0;
}
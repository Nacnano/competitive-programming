#include<bits/stdc++.h>
using namespace std;
const int  mxn = 1e6+10;
const int p =1e9+7;

long long dp[mxn];

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;
	dp[0] = 1;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=6;j++){
			if(i>=j) dp[i] +=dp[i-j];
		}
		dp[i] %= p;
	}
	cout << dp[n];
}
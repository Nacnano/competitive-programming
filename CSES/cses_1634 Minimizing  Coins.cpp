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
	for(int i=0;i<=mxx;i++) dp[i]= mxx;

	dp[0]=0;
	for(int i=1;i<=x;i++){
		for(int j=1;j<=n;j++){
			if(i>=coin[j]) dp[i]=min(dp[i], dp[i-coin[j]]+1);
		}
	}
	cout << (dp[x] != mxx ? dp[x]: -1);

	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define f first
#define s second

const ll p=1e9+7;
const int maxN=1e5+5;
ll dp[10][10][maxN];

int adj[10][5] = {{}, 
			{2, 4, 5}, 
			{1, 3, 6}, 
			{2, 4, 7},
			{1, 3, 8},
			{1, 6, 8},
			{2, 5, 7},
			{3, 6, 8},
			{4, 5, 7}};

void solve(){
	int n, q;
	dp[1][0][0]=1;

	dp[2][1][1]=1;
	dp[4][1][1]=1;
	dp[5][1][1]=1;

	dp[3][2][2]=1;
	dp[3][4][2]=1;
	dp[6][2][2]=1;
	dp[6][5][2]=1;
	dp[8][4][2]=1;
	dp[8][5][2]=1;

	for(int i=3;i<=maxN;i++){
		for(int j=1;j<=8;j++){
			for(int k=0;k<3;k++){
				int prev=adj[j][k];
				for(int l=0;l<3;l++){
					if(j==adj[prev][l]) continue;
					dp[j][prev][i]+=dp[prev][adj[prev][l]][i-1];
					dp[j][prev][i]%=p;
				}
			}
		}
	}

	
	cin >> q;
	while(q--){
		cin >> n;
		
		// for(int i=1;i<=8;i++){
		// 	for(int j=0;j<3;j++){
		// 		cout << i << " " << adj[i][j] << " " << dp[i][adj[i][j]][n] << "\n";
		// 	}
		// }
			ll ans=0;
		for(int i=5;i<=8;i++){
			for(int j=0;j<3;j++){
				ans+=dp[i][adj[i][j]][n];
				ans%p;
			}
		}
		cout << ans%p << "\n";
		
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	#endif

	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t=1;
	// cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define f first
#define s second

const int maxN=100005;

void solve(){
	int n, H, M, ans=1e9;
	cin >> n >>  H >> M;
	int time1=H*60+M;
	while(n--){
		int h, m;
		cin >> h >> m;
		int time2=60*h+m;
		if(time2>=time1) ans=min(time2-time1,ans);
		else ans=min(time2-time1+24*60, ans);
	}
	cout << ans/60 << " " << ans%60 << "\n";
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	#endif

	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t=1;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
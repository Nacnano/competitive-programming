#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define f first
#define s second

const int maxN=100005;

void solve(){
	int n, x, a, ans=0;
	cin >> n >> x >> a;
	int mx=a, mn=a;
	for(int i=1;i<n;i++){
		cin >> a;
		if(a>mx){
			mx=a;
		}
		if(a<mn){
			mn=a;
		}
		if(mx-mn>2*x){
			ans++;
			mx=a;
			mn=a;
		}
	}
	cout << ans << "\n";

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
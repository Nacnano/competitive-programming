#include<bits/stdc++.h>
using namespace std;
const int mxn = 105;

long long n, w, c[mxn], ans;

void calc(long long lv, long long w){
	if(w < 0){
		cout << "-1";
		exit(0);
	}
	if(lv == 1){
		ans += w;
		return;
	} 
	calc(lv-1, w-c[lv-1]/2);
	calc(lv-1, w-c[lv-1]/2);
}
	

void solve(){
	cin >> n >> w;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	ans = 0;
	calc(n, w);
	cout << ans;
}

int main(){
	// tesing sublime text
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(NULL);

	int t=1;
	// cin >> t;
	while(t--){
		solve();
	}
	return 0;
}

/*

3 1
1 1

3 10
9 9

20 1000000000
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 

*/

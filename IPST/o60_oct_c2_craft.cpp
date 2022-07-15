#include<bits/stdc++.h>
using namespace std;
const int mxn = 105;

long long n, w, c[mxn], ans=0;

void calc(long long lv, long long w){
	if(lv == 1){
		if(w <= 0){
			cout << "-1";
			exit(0);
		}
		else{
			ans += w;
			return;
		}
	} 
	
	w = w*2 - c[--lv] + 1;
	if(w%2){
		calc(lv, w/2);
		calc(lv, w/2+1);
	} 
	else{
		calc(lv, w/2);
		calc(lv, w/2);
	}
	return;
}
	
void solve(){
	cin >> n >> w;
	for(int i=1;i<n;i++) cin >> c[i];

	ans = 0;
	calc(n, w);
	cout << ans;
}

int main(){
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
#include<bits/stdc++.h>
using namespace std;
const int mxn = 200005;

void solve(){
	int n;
	int a[mxn], ans=0, cnt=0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=n-2;i>=0;i--){
		if(a[i]){
			ans+=cnt+a[i];
			cnt=0;
		}
		else{
			cnt++;
		}
	}
	cout << ans << "\n";

}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int maxN = 200005;
int a[maxN], n;
long long qs[2][maxN];


void solve(){
	int n, m;
	cin >> n >> m >> a[1];
	for(int i=2;i<=n;i++){
		cin >> a[i];
		if(a[i]-a[i-1]<=0) qs[0][i]=a[i]-a[i-1];
		else qs[1][i-1]=a[i-1]-a[i];
	}
	for(int i=2;i<=n;i++) qs[0][i]+=qs[0][i-1];
	for(int i=n+1;i>=1;i--) qs[1][i-1]+=qs[1][i];
	// for(int i=1;i<=n;i++) cout << qs[1][i] << " ";

	while(m--){
		int s, t;
		cin >> s >> t;
		if(s<t) cout << qs[0][s]-qs[0][t] << "\n";
		else cout << qs[1][s]-qs[1][t] << "\n";

	}
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
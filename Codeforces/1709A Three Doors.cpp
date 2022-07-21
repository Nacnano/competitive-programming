#include<bits/stdc++.h>
using namespace std;
const int maxN = 5;
int a[maxN], n;


void solve(){
	int now;
	cin >> now;
	for(int i=1;i<=3;i++) cin >> a[i];


	for(int i=0;i<=3;i++){
		int tmp_now=now;
		now=a[now];
		a[tmp_now]=-1;
	}
	int cnt=0;
	for(int i=1;i<=3;i++) if(a[i]==-1)cnt++;
	if(cnt==3) cout << "YES\n";
	else cout << "NO\n";
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(NULL);

	int t=1;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
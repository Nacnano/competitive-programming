#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define f first
#define s second

const ll p=1e9+7;
const int maxN=200005;

void solve(){
	int n;
	int a[maxN];
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	if(n==1){
		cout << "YES\n";
		return;
	}
	int cnt=0;
	for(int l=0, r=0;l<n;l=r){
		while (r<n && a[l]==a[r]) r++;
		if((l==0 || a[l]<a[l-1])&&(r==n||a[r]>a[r-1])) cnt++;
	}
	cout << (cnt == 1 ? "YES\n": "NO\n");

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


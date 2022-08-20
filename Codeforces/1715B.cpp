#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define f first
#define s second

const ll p=1e9+7;
const int maxN=115;

void solve(){
	long long n, k, b, s;
	cin >> n >> k >> b >> s;

	if(s>b*k+n*(k-1)){
		cout << "-1\n";
		return;
	}
	if(s<b*k){
		cout << "-1\n";
		return;
	}
	long long need = s-b*k;
	for(int i=0;i<n-1;i++){
		if(need>=k-1){
			cout << k-1 << " ";
			need-=k-1;
		}
		else cout << "0 ";
	}

	cout << b*k+need << "\n";
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
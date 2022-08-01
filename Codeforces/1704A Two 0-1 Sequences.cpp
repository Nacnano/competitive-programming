#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define f first
#define s second

const int maxN=100005;
int n, m;
string a, b;

void solve(){

	cin >> n >> m;
	cin >> a >> b;
	for(int i=1;i<m;i++){
		if(a[i+n-m]!=b[i]){
			cout << "NO\n"; 
			return;
		}
	}
	for(int i=0;i<n-m+1;i++){
		if(a[i]==b[0]){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
	return;
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
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define f first
#define s second

const int maxN=200005;

void solve(){
	int n, a[maxN];
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
		a[i]+=a[i]%10;
		if(a[i]%5){
			a[i]%=20;
			while(a[i]<=20){
				a[i]+=(a[i]%10);
			}
		}
		else{
			a[i]+=a[i]%10;
		}
	}
	for(int i=1;i<n;i++){
		if(a[i]!=a[0]){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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
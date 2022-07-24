#include<bits/stdc++.h>
using namespace std;
const int maxN = 200000;
int a[maxN], n;


void solve(){
	cin >> n;
	
	if(n%2){
		cout << "1 ";
		for(int i=2;i<=n;i+=2){
			cout << i+1 << " " << i << " ";
		}
	}
	else{
		for(int i=1;i<n;i+=2){
			cout << i+1 << " " <<  i << " ";
		}
	}


	cout << "\n";
	return;
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
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define f first
#define s second

const int maxN=100005;

void gen(int st, int last){
	for(int i=st;i<=last;i++){
		cout << i-1 << " " << i << "\n";
	}
}

void solve(){
	int n,a, b, c;
	cin >> n >> a >> b >> c;
	if((a+b+c)%2){
		cout << "NO\n";
		return;
	}
	
	if(a+b>c){

	}
	
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
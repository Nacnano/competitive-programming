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
	int pos=m-1;
	for(int i=n-1;i>=0;i--){
		if(b[pos]==a[i]){
			pos--;
		}
		else if(a[i]=='1') break;
	}
	cout << pos << " ";
	if(pos==-1) cout << "YES\n";
	else cout << "NO\n";
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
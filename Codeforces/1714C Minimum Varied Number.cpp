#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define f first
#define s second

const int maxN=100005;

void solve(){
	int n;
	cin >> n;
	vector<int> ans;
	int cnt=9;
	while(n>=1){
		if(n>=cnt){
			n-=cnt;
			ans.push_back(cnt);
			cnt--;
		}
		else{
			ans.push_back(n);
			n=0;
		}
	}
	for(int i=ans.size()-1;i>=0;i--){
		cout << ans[i];
	}
	cout << "\n";
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
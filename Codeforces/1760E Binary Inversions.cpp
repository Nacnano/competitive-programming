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
	cin >> n;
	int a[maxN];
	long long ones[maxN], zeroes[maxN];
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		ones[i]=ones[i-1]+(a[i]);
	}
	zeroes[n+1]=0;
	for(int i=n;i>=1;i--){
		zeroes[i]=zeroes[i+1]+(a[i]==0);
	}

	for(int i=1;i<=n;i++){
		ans += zeroes[i]*a[i];
	}
	long long ans2=ans;
	for(int i=1;i<=n;i++){
		if(a[i]){
			ans2=max(ans2, ans+ones[i-1]-zeroes[i+1]);
		}
		else{
			ans2=max(ans2, ans+zeroes[i+1]-ones[i-1]);
		}
	}

	cout << ans2 << endl;


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


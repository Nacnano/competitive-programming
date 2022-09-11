#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define f first
#define s second

// const ll p=1e9+7;
const int maxN=2500005;
int p[maxN];
ll v[maxN], qs[maxN];
vector<int> vp;
vector<ll> vv, vqs;

void solve(){
	int n, m, l, u;
	cin >> n >> m >> l >> u;

	vp.push_back(0);
	vv.push_back(0);
	vqs.push_back(0);
	ll sum=0, ans=0;
	for(int i=1;i<=m;i++){
		cin >> p[i] >> v[i];
		vp.push_back(p[i]-1);
		vp.push_back(p[i]);

		vv.push_back(0);
		vv.push_back(v[i]);

		qs[i]=qs[i-1]+v[i];
		vqs.push_back(qs[i-1]);
		vqs.push_back(qs[i]);
		sum+=v[i];
		if(sum<0) sum=0;
		ans=max(ans, sum);


	}



	int left=1, right=1;
	sum=0;
	while(vp[right]<2*l){
		sum=vqs[right];
		ans=max(ans, sum);
		right++;
		// cout << sum << " " << p[left] << " " << p[right] << "\n";
	}
	while(right<(int)vp.size()){
		if(vp[left]<=0){
			left++;
			if(vp[right]-vp[left]>=2*l && vp[right]-p[left]<=2*u){
			sum=vqs[right]-vqs[left-1];
			ans=max(ans, sum);
			continue;
		}
		}
		if(vp[right]-vp[left]>=2*l && vp[right]-vp[left]<=2*u){
			sum=vqs[right]-vqs[left-1];
			ans=max(ans, sum);
		}
		if(vp[right]-vp[left]>2*u){
			left++;
			continue;
		}
		if(vp[right]-vp[left]<2*l){
			right++;
			continue;
		}
		if(vp[right]-vp[left]>=2*l && vp[right]-vp[left]<=2*u){
			sum=vqs[right]-vqs[left-1];
			ans=max(ans, sum);
		}
		// cout << sum << " " << vp[left] << " " << vp[right] << "\n";
		if(v[right+1]-v[left]<=2*u && v[right])

		left++;

	}
	right--;
	while(vp[right]-vp[left]>=2*l && vp[right]-vp[left]<=2*u){
		sum=vqs[right]-vqs[left-1];
		ans=max(ans, sum);
		left++;
		// cout << sum << " " << vp[left] << " " << vp[right] << "\n";
	}
	cout << ans;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	#endif

	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t=1;
	// cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

long long a[50010], s, ans=INT_MIN;;
set<long long> ss;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	cin >> s;
	ss.insert(a[0]);
	for(int i=1;i<n;i++)
	{
		auto it=lower_bound(ss.begin(),ss.end(),a[i]-s);
		ss.insert(a[i]);
		if(it==ss.end()) continue;
		ans=max(ans,*it+a[i]);
	}
	cout << ans;
	return 0;
}

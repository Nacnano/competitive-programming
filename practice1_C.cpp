#include<bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	int n, q, x;
	cin >> n >> q;
	for(int i=0;i<n;i++) cin >> x, v.push_back(x);
	sort(v.begin(),v.end());
	
	while(q--)
	{
		cin >> x;
		int l=0, r=n-1;
		while(l<r)
		{
			int md=l+(r-l)/2;
			if(v[md]<x) l=md+1;
			else r=md;
		}
		if(l==n) cout << v[n-1] << "\n";
		else if(l==0) cout << v[0] << "\n";
		else
		{
			int mn=min(v[l]-x,x-v[l-1]);
			if(mn==x-v[l-1]) cout << v[l-1]<< "\n";
			else cout << v[l] << "\n";
		}
	}
	return 0;
}

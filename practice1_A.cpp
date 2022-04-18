#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	int n, q;
	cin >> n >> q;
	for(int i=0;i<n;i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	
	sort(v.begin(),v.end());
	while(q--)
	{
		int x;
		cin >> x;
		int l=0, r=n-1;
		while(l<r)
		{
			int md=l+(r-l)/2;
			if(v[md]>=x) r=md;
			else l=md+1;
		}
		if(v[l]==x) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}

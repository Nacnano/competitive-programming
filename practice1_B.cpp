#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > v;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	int n, q;
	cin >> n >> q;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin >> x;
		v.push_back({x,i});
	}
	sort(v.begin(),v.end());
	v.push_back({1e9+10,-1});
	
	while(q--)
	{
		int x;
		cin >> x;
		int l=0, r=n-1;
		while(l<r)
		{
			int md=l+(r-l)/2;
			if(v[md].first>=x) r=md;
			else l=md+1;
		}
		if(v[l].first!=x) cout << "-1 -1\n";
		else
		{
			cout << v[l].second << " ";
			int lo=0,hi=n-l;
			while(lo<hi)
			{
				int mid=lo+(hi-lo)/2;
				if(v[l+mid].first>=x+1) hi=mid;
				else lo=mid+1;
			}
			cout << v[l+lo-1].second << "\n";
		}
	}
	return 0;
}

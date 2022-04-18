#include<bits/stdc++.h>
using namespace std;

set<int> ss;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	int n, q;
	cin >> n >> q;
	while(n--)
	{
		int x;
		cin >> x;
		ss.insert(x);
	}
	while(q--)
	{
		int x;
		cin >> x;
		if(ss.find(x)==ss.end()) cout << "NO" << "\n";
		else cout << "YES" << "\n";
	}
	
	return 0;
}

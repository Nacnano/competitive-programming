#include<bits/stdc++.h>
using namespace std;

set<int> ss;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	int n;
	cin >> n;
	
	int l=1, r=90000, ans;
	while(l<r)
	{
		int md=l+(r-l)/2, i=1, sum=0;
		while(i<=md)
		{
			sum+=md/i;
			i++;
		}
		if(sum>=n) r=md;
		else l=md+1;
	}
	cout << l;
	
	return 0;
}

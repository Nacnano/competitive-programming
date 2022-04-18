/*
	I don't know but can't you just brute force this problem?
	The constrains are not that big.
*/

#include<bits/stdc++.h>
using namespace std;

long long calc(long long x){
	return 42*x*x*x+13*x*x+1336*x;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	long long c, l=0, r=2e5+1, ans;
	cin >> c;
	while(l<r)
	{
		long long md=l+(r-l)/2;
		if(calc(md)>c) r=md;
		else l=md+1;
	}
	cout << --l;
	return 0;
}

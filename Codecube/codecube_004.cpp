#include<bits/stdc++.h>
using namespace std;

int _gcd(int a,int b)
{
	if(!b) return a;	
	return _gcd(b,a%b);
}

int main(){
	ios_base::sync_with_stdio(NULL), cin.tie(NULL);
	
	int n,div;
	long long sum;
	cin >> n >> sum;
	div=sum;
	
	n--;
	while(n--)
	{
		int x;
		cin >> x;
		sum+=x;
		div=_gcd(div,x);	
	}
	cout << sum/div;
}

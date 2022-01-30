#include<bits/stdc++.h>
using namespace std;

int main(){
	
	long long n;
	scanf("%lld",&n);
	
	long long ans=1e12;
	for(long long i=1;i*i<=n;i++)
	{
		if(n%i) continue;
		
		ans=min(ans,(i+n/i)-2);
	}
	printf("%lld",ans);
	
}

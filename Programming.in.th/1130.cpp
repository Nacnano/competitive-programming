#include<bits/stdc++.h>
using namespace std;

long long a[10010], p=49999;

int main(){
	
	int n;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	
	long long mul=1;
	for(int i=2;i<n-1;i++)
	{
		mul*=i;
		mul%=p;
	}
	
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			ans+=abs(a[i]-a[j])*mul;
			ans%=p;
		}
	}
	printf("%lld",ans);
}

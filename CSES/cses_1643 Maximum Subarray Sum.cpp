#include<bits/stdc++.h>
using namespace std;

long long sum=0,ans=0,mx=-1e9;

int main(){
	
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		long long x;
		scanf("%lld",&x);
		sum+=x;
		ans=max(ans,sum);
		mx=max(mx,x);
		if(sum<0)sum=0;
	}
	if(ans>0) printf("%lld",ans);
	else printf("%lld",mx);
}

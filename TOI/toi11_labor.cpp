#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
int main(){
	
	long long m,n;
	scanf("%lld%lld",&m,&n);
	
	for(int i=0;i<m;i++)
	{
		scanf("%lld",&a[i]);
	}
	
	long long st=0,ed=1e18,mid;
	while(st<ed)
	{
		mid=(st+ed)/2;
		long long sum=0;
		for(int i=0;i<m;i++) sum+=mid/a[i];
		
		if(sum>=n) ed=mid;
		else st=mid+1;
	}
	
	printf("%lld",st);
	return 0;
}

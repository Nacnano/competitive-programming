#include<bits/stdc++.h>
using namespace std;

int main(){
	
	long long w,l,n,m;
	scanf("%lld%lld%lld%lld",&w,&l,&m,&n);
	
	long long ans=w*l;
	for(int i=m;i<=n;i++)
	{
		long long area=w*l;
		long long non=w,tung=l;
		area-=tung*(non/i)*i;
		
		non=l;
		tung=w%i;
		area-=tung*(non/i)*i;
		
		ans=min(ans,area);
	}	
	printf("%lld",ans);
}

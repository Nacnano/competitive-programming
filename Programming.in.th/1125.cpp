#include<bits/stdc++.h>
using namespace std;

vector<long long> vx,vy;

int main(){
	
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		long long x,y;
		scanf("%lld %lld",&x,&y);
		vx.push_back(x);
		vy.push_back(y);
	}
	
	sort(vx.begin(),vx.end());
	sort(vy.begin(),vy.end());
	
	long long ans=0; 
	for(int i=0;i<n/2;i++)
	{
		ans+=(n-1-i-i)*(vx[n-1-i]-vx[i]);
		ans+=(n-1-i-i)*(vy[n-1-i]-vy[i]);
	}
	printf("%lld",ans);
}

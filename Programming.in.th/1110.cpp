#include<bits/stdc++.h>
using namespace std;

int a[1000010], qs[1000010];
long long cntr[2000010],cntl[2000010];

int main(){
	
	int n,k,mk;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]==k) mk=i; 
		else if(a[i]>k) qs[i]=1;
		else qs[i]=-1;
	}
	
	for(int i=mk-1;i>=1;i--)
	{
		qs[i]+=qs[i+1];
		cntr[1000000+qs[i]]++;
	}
	for(int i=mk+1;i<=n;i++)
	{
		qs[i]+=qs[i-1];
		cntl[1000000+qs[i]]++;
	}
	
	long long ans= cntl[1000000]+cntr[1000000]+cntr[1000000]*cntl[1000000];
	for(int i=1;i<=n/2;i++) ans+=cntl[1000000+i]*cntr[1000000-i]+cntr[1000000+i]*cntl[1000000-i];
	printf("%lld",ans+1);
}

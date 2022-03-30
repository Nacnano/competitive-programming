#include<bits/stdc++.h>
using namespace std;

const long long md=1e6+7;
long long fac[3010];

int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	
	fac[0]=1;
	for(int i=1;i<=3000;i++) fac[i]=fac[i-1]*i,fac[i]%=md;
	
	if(n+2*m<k || (k-n)%2!=0) 
	{
		printf("0");
		return 0;
	}
	
	long long ans=0;
	int cnt1,cnt2;
	if(k<=n) cnt1=k,cnt2=0;
	else cnt1=n,cnt2=(k-n)/2;
	while(cnt1<=n && cnt1>=0 && cnt2<=m && cnt2>=0)
	{
	//	printf("%d %d %lld\n",cnt1,cnt2,fac[cnt1+cnt2]);
		ans+=fac[cnt1+cnt2];
		ans%=md;
		
		cnt1-=2;
		cnt2++;
	}
	printf("%lld",ans);
	return 0;
}

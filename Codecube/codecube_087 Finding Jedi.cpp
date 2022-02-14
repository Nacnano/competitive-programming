#include<bits/stdc++.h>
using namespace std;

int cnt[1000010];
int main(){
	
	int n, m, x;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	
	long long ans=0;
	for(int i=0;i<=(m-1)/2;i++) ans+=(long long)cnt[i]*cnt[m-i];
	if(m%2==0) ans+=(long long)cnt[m/2]*(cnt[m/2]-1)/2;
	printf("%lld",ans);
}

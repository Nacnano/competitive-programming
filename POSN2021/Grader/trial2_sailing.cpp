#include<bits/stdc++.h>
using namespace std;

long long sum[1000010];

int main(){
	
	int n,m;
	scanf("%d%d",&n,&m);
	
	while(n--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		sum[a]+=c;
		sum[b+1]-=c;
	}
	for(int i=1;i<=1000000;i++) sum[i]+=sum[i-1];
	
	while(m--)
	{
		int x;
		scanf("%d",&x);
		printf("%lld\n",sum[x]);
	}
}

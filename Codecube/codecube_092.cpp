#include<bits/stdc++.h>
using namespace std;

double val=1;
int dig[100005];

int main(){
	
	dig[0]=1;
	for(int i=1;i<=1e5;i++)
	{
		val*=i;
		int cnt=0;
		while(val>=10)
		{
			val/=10;
			cnt++;
		}
		dig[i]=dig[i-1]+cnt;
	}
	
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",dig[n]);
	}
}

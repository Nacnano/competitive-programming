#include<bits/stdc++.h>
using namespace std;

int r[20010];
int p[20010];

int dp[20010];

int main(){
	
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&r[i]);
	}
	r[0]=0;
	r[m+1]=n;
	
	for(int i=0;i<k;i++)
	{
		scanf("%d",&p[i]);
	}
	
	for(int i=0;i<=m;i++)
	{
		for(int j=min(i,k-1);j>=0;j--)
		{
			dp[j+1]=max(dp[j],dp[j+1])+p[j]*(r[i+1]-r[i]);
		}
	}
	
	printf("%d\n",dp[k]);
    
}

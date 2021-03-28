#include<bits/stdc++.h>
using namespace std;

int cost[300];

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	
	int all=pow(2,k);
	
	for(int i=0;i<all;i++) cost[i]=2e9;
	cost[0]=0;

	for(int i=1;i<=n;i++)
	{
		int w,p;
		scanf("%d",&w);
		
		int can=0;
		int mul=1;
		for(int j=1;j<=k;j++)
		{
			scanf("%d",&p);
			can+=mul*p;
			mul*=2;
		}
		for(int j=all-1;j>=0;j--)
		{
			cost[j | can]=min(cost[j | can],cost[j]+w);
		}
	}
	
	printf("%d",cost[all-1]);	
}

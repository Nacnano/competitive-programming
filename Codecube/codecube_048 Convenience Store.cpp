#include<bits/stdc++.h>
using namespace std;

const int p=1e6+7;
int c[510];
int dp[50110];

int main(){
	
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&c[i]);
	
	dp[0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=m;j>=0;j--)
		{
			dp[j+c[i]]+=dp[j];
			dp[j+c[i]]%=p;
		}
	}
	printf("%d",dp[m]);
}

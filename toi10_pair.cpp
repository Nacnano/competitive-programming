#include<bits/stdc++.h>
using namespace std;

int dp[1010][1010];
char s[1010];

int main(){
	
	int k;
	cin >> k;
	
	for(int i=1;i<=k;i++)
	{
		cin >> s[i];
	}
	
	for(int l=1;l<k;l++)
	{
		for(int i=1;i+l<=k;i++)
		{
			for(int j=i;j<i+l;j++)
			{
				if(s[i]==s[i+l])
				{
					dp[i][i+l]=max(dp[i+1][i+l-1]+1,dp[i][i+l]);
					break;
				}
				else
				{
					dp[i][i+l]=max(dp[i][j]+dp[j+1][i+l],dp[i][i+l]);
				}
			}	
		}
	}
	
	cout << dp[1][k];
}


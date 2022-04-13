#include<bits/stdc++.h>
using namespace std;
const long long p=1e9+7;

string s[1010];
long long dp[1010][1010];

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++) cin >> s[i];
	if(s[0][0]=='*')
	{
		cout << "0";
		return 0;
	}
	
	dp[0][0]=1;
	for(int i=1;i<n;i++) if(s[0][i]=='.') dp[0][i]+=dp[0][i-1]; else break;
	for(int i=1;i<n;i++) if(s[i][0]=='.') dp[i][0]+=dp[i-1][0]; else break;
	
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(s[i][j]=='*') continue;
			if(s[i][j-1]=='.') dp[i][j]+=dp[i][j-1];
			if(s[i-1][j]=='.') dp[i][j]+=dp[i-1][j];
			dp[i][j] = dp[i][j] % p;
		}
	}
	cout << dp[n-1][n-1];
}

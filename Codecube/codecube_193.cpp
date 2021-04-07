#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > food;
long long dp[100005];
long long back1[100005],back2[100005];
int main(){
	
	int n,k;
	scanf("%d%d",&n,&k);
	
	for(int i=0;i<n;i++)
	{
		int x,c;
		scanf("%d%d",&x,&c);
		food.push_back({x,c});
	}
	
	sort(food.begin(),food.end());
	for(int i=1;i<n;i++)
	{
		if(food[i].first - food[i-1].first <= k) back1[i] = food[i-1].second + food[i].second - (food[i].first - food[i-1].first);
		
		if(i>1)
		if(food[i].first - food[i-2].first <= k) back2[i] = food[i-2].second + food[i].second - (food[i].first - food[i-2].first);
	}
	
	dp[1]=0;
	for(int i=2;i<=n;i++)
	{
		dp[i]=max(dp[i], dp[i-2]+back1[i-1]);
		if(i>1)
		dp[i]=max(dp[i], dp[i-3]+back2[i-1]);
		dp[i+1]=dp[i];
	}
	printf("%lld",dp[n+1]);
}

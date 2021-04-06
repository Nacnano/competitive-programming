#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > bomb;
vector<pair<int,int> > ans;
int main(){
	
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		bomb.push_back({x,-y});
	}
	
	sort(bomb.begin(),bomb.end(),greater<pair<int,int>>());
	int ynow = -bomb[0].second;
	int xmax= bomb[0].first;
	ans.push_back({bomb[0].first,bomb[0].second});
//	for(auto x:bomb) printf("%d %d\n",x.first,x.second);
//	printf("\n");
	for(int i=1;i<n;i++)
	{
		if(xmax > bomb[i].first && ynow > -bomb[i].second) continue;
		ynow = max(ynow,-bomb[i].second);
		ans.push_back({bomb[i].first,bomb[i].second});
	}
	sort(ans.begin(),ans.end());
	for(auto x:ans) printf("%d %d\n",x.first,-x.second);
}

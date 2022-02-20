#include<bits/stdc++.h>
using namespace std;

pair<int,pair<int,int> > ans[100010];
int cnt[100010];

int main(){
	
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++)
	{
		int idx,row,speed;
		scanf("%d%d%d",&idx,&row,&speed);
		int col=++cnt[row];
		
		if(speed>ans[col].second.first)
		{
			ans[col].first=idx;
			ans[col].second.first=speed;
			ans[col].second.second=row;
		}
		else if(speed==ans[col].second.first && row < ans[col].second.second)
		{
			ans[col].second.second = row;
			ans[col].first=idx;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(ans[i].first) printf("%d\n",ans[i].first);
		else break;
	}
}

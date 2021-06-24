#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > v;

int main(){
	
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v.push_back({b,a});
	}
	
	sort(v.begin(),v.end());
	
	int ans=0;
	int ed=0;
	for(auto now: v)
	{
		if(now.second >= ed)
		{
			ed=now.first;
			ans++;
		}
	}
	printf("%d",ans);
}

#include<bits/stdc++.h>
using namespace std;

const int mxn=5e5+5;
vector<pair<long long,long long> > vx,vy;

int main(){
	
	int n;
	scanf("%d",&n);
	
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		long long x,y,s;
		scanf("%lld%lld%lld",&x,&y,&s);
		vx.push_back({x,s});
		vy.push_back({y,s});
		cnt+=s;
	}
	sort(vx.begin(),vx.end());
	sort(vy.begin(),vy.end());
	
	int now=0;
	int tx,ty;
	for(auto it:vx)
	{
		now+=it.second;
		
		if(now>=cnt/2)
		{
			tx=it.first;
			break;
		}
	}
	
	now=0;
	for(auto it: vy)
	{
		now+=it.second;
		
		if(now>=cnt/2)
		{
			ty=it.first;
			break;
		}
	}
	
	long long dis=0;
	for(int i=0;i<n;i++)
	{
		dis+=vx[i].second*abs(vx[i].first-tx);
		dis+=vy[i].second*abs(vy[i].first-ty);
	}
	printf("%lld",dis);
}

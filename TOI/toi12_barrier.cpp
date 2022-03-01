#include<bits/stdc++.h>
using namespace std;

int len=0;
long long qs[6000010], a[6000010], ans=0;
deque<pair<long long,int> > dq;

int main(){
	
	qs[0]=0;
	int n, w;
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		qs[i]=qs[i-1]+a[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		while(!dq.empty() && qs[i]<=dq.back().first) dq.pop_back();
		while(!dq.empty() && dq.front().second<i-w) dq.pop_front();
		dq.push_back({qs[i],i});
		if(i==dq.front().second) continue;
		else if(qs[i]-dq.front().first>ans)
		{
			ans=qs[i]-dq.front().first;
			len=i-dq.front().second;
		}
		else if(qs[i]-dq.front().first==ans) len=min(len, i-dq.front().second);
	}
	printf("%lld\n%d",ans,len);
}

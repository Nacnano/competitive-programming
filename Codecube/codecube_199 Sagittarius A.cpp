#include<bits/stdc++.h>
using namespace std;

int p[100010];
vector<pair<pair<int,int>,pair<int,int> > > e;
vector<int> ans2;

int _find(int x)
{
	if(p[x]==x) return x;
	else return p[x]=_find(p[x]);
}

int main(){
	
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) p[i]=i;
	
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e.push_back({{w,i},{u,v}});
	}
	
	long long ans1=0,cnt=1;
	sort(e.begin(),e.end());
	for(int i=m-1;i>=0;i--)
	{
		int pu=_find(e[i].second.first);
		int pv=_find(e[i].second.second);
		
		if(pv!=pu)
		{	
			p[pv]=pu;
			ans1+=1ll*e[i].first.first;
			ans2.push_back(e[i].first.second);
		}
		else if(pv==pu && cnt)
		{
			ans1+=1ll*e[i].first.first;
			ans2.push_back(e[i].first.second);
			cnt=0;
		}
	}
	
	int t;
	scanf("%d",&t);
	if(ans2.size()!=n) printf("-1");
	else if(t==1) printf("%lld",ans1);
	else if(t==2)
	{
		printf("%lld\n",ans1);
		for(auto x:ans2) printf("%d ",x);
	}
}

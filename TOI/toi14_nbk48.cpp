#include<bits/stdc++.h>
using namespace std;

int qs[100005];
map<int,int> mm;
vector<int> cost;

int main(){
	
	int n,q;
	scanf("%d%d",&n,&q);
	
	qs[0]=0;
	mm[0]=0;
	cost.push_back(0);
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		qs[i] = qs[i-1]+a;
		cost.push_back(qs[i]);
		mm[qs[i]] = max(i,mm[qs[i]]);
	}
	cost.push_back(INT_MAX);
	
	sort(cost.begin(),cost.end());
	int mx;
	for(auto it=cost.begin();it!=cost.end();it++)
	{
		if(it==cost.begin())
		{
			mx=mm[*it];
			continue;
		}
		if(mx > mm[*it]) mm[*it] = mx;
		else mx = mm[*it];
	}

	while(q--)
	{
		int p;
		scanf("%d",&p);
		auto it=lower_bound(cost.begin(),cost.end(),p);
		if(*it > p) it--;

		printf("%d\n",mm[*it]);
	}
}

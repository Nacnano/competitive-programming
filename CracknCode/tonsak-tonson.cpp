#include<bits/stdc++.h>
using namespace std;

int a[100010];
vector<pair<int,int> > v;
vector<pair<int,int> > diff;

bool cmp(pair<int,int> a,pair<int,int> b)
{
	if(a.first > b.first) return 1;
	else if(a.first==b.first && a.second <= b.second) return 1;
	else return 0;
}

int main(){
	
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		v.push_back({a[i],i});
	}
	
	sort(v.begin(),v.end());
	for(auto tmp:v) printf("%d %d\n",tmp.first,tmp.second);
	printf("\n");
	
	
	for(auto tmp:v)
	{
		diff.push_back({abs(tmp.first-tmp.second),tmp.second});
	}
	
	sort(diff.begin(),diff.end(),cmp);
//	for(auto tmp:diff) printf("%d %d\n",tmp.first,tmp.second);

	int ans1=diff[0].second;
	int ans2=diff[1].second;
	printf("%d %d",min(ans1,ans2),max(ans1,ans2));
	return 0;
}

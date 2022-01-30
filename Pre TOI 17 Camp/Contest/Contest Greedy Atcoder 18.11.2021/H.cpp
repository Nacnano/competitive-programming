#include<bits/stdc++.h>
using namespace std;


vector<pair<int,int> > v;

bool cmp(pair<int,int> a, pair<int,int> b)
{
	return a.second<b.second;
}

int main(){
	
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		int x,l;
		scanf("%d%d",&x,&l);
		v.push_back({x-l,x+l});
	}
	
	sort(v.begin(),v.end());
	
	int ans=0;
	int cnt=0;
	int t=INT_MIN;
	for(auto tmp:v)
	{
		if(t<=tmp.first) ans++;
		else t=tmp.second;
	}
	printf("%d",ans);
}

#include<bits/stdc++.h>
using namespace std;

long long a[200010],b[200010];
vector<pair<long long,long long > > v;

int main(){
	
	int n;
	scanf("%d",&n);
	
	long long suma=0,sumb=0;
	for(int i=1;i<=2*n-1;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
		v.push_back({a[i]+b[i],i});
		suma+=a[i];
	}
	
	sort(v.begin(),v.end(), greater<pair<long long,long long> >());
	
	long long sumn=0;
	for(int i=0;i< n;i++)
	{
		sumn+=v[i].first;
	}
	
	if(sumn*2 < suma)
	{
		printf("-1");
		return 0;
	}
	
	for(int i=0;i<n;i++)
	{
		printf("%d ",v[i].second);
	}
}


/*
3
1 1
2 2
3 2
4 4
6 6

*/

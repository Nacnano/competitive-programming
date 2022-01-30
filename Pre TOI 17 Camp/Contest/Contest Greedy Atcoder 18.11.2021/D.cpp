#include<bits/stdc++.h>
using namespace std;

vector<long long> v;
map<long long,int> mm;
int main(){
	
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		long long x;
		scanf("%lld",&x);
		mm[x]++;
		if(mm[x]==2)
		{
			v.push_back(x);
			mm[x]-=2;
		}
	}
	
	sort(v.begin(),v.end());
	if(v.size()<=1) printf("0");
	else printf("%lld",v[v.size()-1]*v[v.size()-2]);
}

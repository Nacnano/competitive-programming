#include<bits/stdc++.h>
using namespace std;

int a[5000010];
vector<int> tmp,v;

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	a[0]=a[n+1]=0;
	for(int i=1;i<=n;i++) if(a[i]>a[i-1] && a[i]>a[i+1]) v.push_back(a[i]);
	
	if(v.empty())
	{
		printf("-1");
		return 0;
	}
	sort(v.begin(),v.end(),greater<int> ());
	
	int dup=0;
	for(auto x:v)
	{
		if(x==dup) continue;
		dup=x;
		tmp.push_back(x);
	}
	
	if(tmp.size()>=k) for(int i=0;i<=k-1;i++) printf("%d\n",tmp[i]);
	else for(int i=(int)tmp.size()-1;i>=0;i--) printf("%d\n",tmp[i]);
}

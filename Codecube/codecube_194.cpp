#include<bits/stdc++.h>
using namespace std;

vector<int> lis;
int a[100005];
long long sum[100005];
int main(){
	
	int n;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	
	while(n--)
	{
		int it=upper_bound(lis.begin(), lis.end(), a[n], greater<int>()) - lis.begin();
		
		if(it == lis.size()) lis.push_back(a[n]);
		else lis[it]=a[n];
		
		sum[it+1]=sum[it]+a[n];		
	}
	printf("%d %lld",lis.size(),sum[lis.size()]);
}

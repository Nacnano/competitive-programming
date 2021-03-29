#include<bits/stdc++.h>
using namespace std;

int INF=1e9;
int a[1000010];
vector<int> v(1000010,INF);

int main(){
	
	int n;
	scanf("%d",&n);
	
	v[0]=-INF;
	int lis=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		
		int it=upper_bound(v.begin(),v.end(),a[i])-v.begin();
		
		if(v[it-1]<=a[i] && a[i]<=v[it])
		{
			v[it]=a[i];
			lis=max(lis,it);
		}
	}
	
	printf("%d",n-lis);
}

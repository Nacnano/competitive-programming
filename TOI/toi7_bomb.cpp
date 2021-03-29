#include<bits/stdc++.h>
using namespace std;

pair<int,int> arr[1000010];

int main(){
	
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&arr[i].first,&arr[i].second);
	}
	sort(arr,arr+n);
	reverse(arr,arr+n);
	
	int mx=0, y=0, now=0;
	
	for(int i=0;i<n;i++)
	{
		if(arr[i].first!=now)
		{
			y=mx;
			now=arr[i].first;
		}
		
		if(arr[i].second>=y) printf("%d %d\n",arr[i].first,arr[i].second);
		
		mx=max(mx,arr[i].second);
	}
}

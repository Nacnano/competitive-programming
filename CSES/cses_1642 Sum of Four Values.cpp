#include<bits/stdc++.h>
using namespace std;

int a[1010];
map<int,pair<int,int> > mm;

int main(){
	
	int n,x;
	scanf("%d%d",&n,&x);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	
	for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) mm[a[i]+a[j]]={i,j};
	
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(mm.find(x-a[i]-a[j])==mm.end()) continue;
			pair<int,int> tmp=mm[x-a[i]-a[j]];
			if(tmp.first!=i && tmp.second!=j && tmp.first!=j && tmp.second!=i)
			{
				printf("%d %d %d %d",tmp.first+1,tmp.second+1,i+1,j+1);
				return 0;
			}
		}
	}
	printf("IMPOSSIBLE");
}

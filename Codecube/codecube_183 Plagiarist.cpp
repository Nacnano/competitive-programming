#include<bits/stdc++.h>
using namespace std;

int a[200010];
int ft[200010];
int n;

void update(int idx,int val)
{
	for(;idx<=n;idx+=idx&-idx) ft[idx]+=val;
}

 int query(int idx)
 {
 	int ret=0;
 	for(;idx>0;idx-=idx&-idx)
 	{
 		ret+=ft[idx];
	}
	return ret;
 }

int main(){
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		update(i,1);
	}
	int q=n;
	while(q--)
	{
		int b;
		scanf("%d",&b);
		int l=1,r=n, ita=0;
		while(l<=r)
		{
			int md=(l+r)/2;
			int it=query(md);
			if(it==b) ita=md;
			if(it>b) r=md-1;
			else l=md+1;
		}
	//	for(int i=1;i<=10;i++) printf("%d ",ft[i]);
		printf("%d\n",a[ita]);
		update(ita+1,-1);
	}	
}

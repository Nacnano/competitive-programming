#include<bits/stdc++.h>
using namespace std;

const int mxn=100000;

int ft[2*mxn+10];

void update(int idx,int val)
{
	for(++idx;idx<=mxn;idx+=idx&-idx) ft[idx]+=val;
}

int query(int idx)
{
	int ret=0;
	for(++idx;idx>0;idx-=idx&-idx) ret+=ft[idx];
	return ret;
}

int main(){
	
	int q;
	scanf("%d",&q);
	while(q--)
	{
		 int t,a,b;
		scanf("%d%d%d",&t,&a,&b);
		
		if(t==1) update(a,b);
		else printf("%d\n",query(b)-query(a-1));
	}
	
}

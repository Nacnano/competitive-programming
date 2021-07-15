#include<bits/stdc++.h>
using namespace std;

int have[1000010];

int main(){
	int n,p;
	scanf("%d%d",&n,&p);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a>b) swap(a,b);
		have[a]++;
		have[b+1]--;
	}
	
	bool chk=0;
	int cnt=0, r=-1, l=INT_MAX;
	for(int i=0;i<=1000000;i++)
	{
		cnt+=have[i];
		if(cnt==n)
		{
			chk=1;
			r=max(l,i);
			l=min(l,i);
		}
	}
	if(chk) printf("%d",min(abs(p-l),abs(p-r)));
	else printf("-1");
	return 0;
}

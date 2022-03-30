#include<bits/stdc++.h>
using namespace std;
const int mxn=1e5+5;
int cnt[mxn];

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		cnt[a]++;
		cnt[b-1]--;
	}
	
	if(cnt[0]==n) 
	{
		printf("yes 0");
		return 0;
	}
	
	int ans=0,sl=cnt[0],mx=0;
	for(int i=1;i<=100000;i++)
	{
		sl+=cnt[i];
		if(sl>mx)
		{
			mx=sl;
			ans=i;
		}
	}
	
	if(mx!=n) printf("no ");
	else printf("yes ");
	printf("%d",ans);
}

#include<bits/stdc++.h>
using namespace std;

int a,b,c,d,e,f,g,h,i;

int check(int num)
{
	int ret=0;
	if((a+i)/2==num) ret++;
	if((d+f)/2==num) ret++;
	if((b+h)/2==num) ret++;
	if((g+c)/2==num) ret++;
	if((a+c)/2==b) ret++;
	if((g+i)/2==h) ret++;
	if((a+g)/2==d) ret++;
	if((c+i)/2==f) ret++;
	
	return ret;
}


int main(){
	
	int t;
	scanf("%d",&t);
	
	for(int q=1;q<=t;q++)
	{
		scanf("%d%d%d",&a,&b,&c);
		scanf("%d%d",&d,&f);
		scanf("%d%d%d",&g,&h,&i);
		
		int ans=-1;
		ans=max(ans,check((a+i)/2));
		ans=max(ans,check((d+f)/2));
		ans=max(ans,check((b+h)/2));
		ans=max(ans,check((g+c)/2));
		
		printf("Case #%d: %d\n",q,ans);
	}
}

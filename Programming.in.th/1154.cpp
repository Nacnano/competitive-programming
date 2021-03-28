#include<bits/stdc++.h>
using namespace std;

char s[15010];
int prime=1e9+7;

int main(){
	
	int n,m;
	scanf("%d%d",&n,&m);
	
	scanf("%s",&s);
	
	int st=1,ed=n-1;
	int ans=0;
	while(st<=ed)
	{
		int mid=(st+ed)/2;
		
		long long hsh=0,mul=1;
		
		map<long long,int> mm;
		
		for(int i=0;i<mid;i++)
		{
			hsh+=s[i];
			hsh*=prime;
			mul*=prime;	
		}
		
		mm[hsh]++;
		int mx=1;
	//	printf("%c %lld\n",s[mid-1],mm[hsh]);
		for(int i=mid;i<n;i++)
		{
			hsh-=s[i-mid]*mul;
			hsh+=s[i];
			hsh*=prime;
			int x=mm[hsh]++;
		//	printf("X %c %lld\n",s[i],x+1);	
			mx=max(mx,x+1);
		}
		
		if(mx<m) ed=mid-1;
		else 
		{
			st=mid+1;
			ans=max(mid,ans);
		}	
	//	printf("%d %d %d\n\n",mid,st,ed);	
	}
	printf("%d",ans);
	
}

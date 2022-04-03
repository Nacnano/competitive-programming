#include<bits/stdc++.h>
using namespace std;
char s[5000010];
long long 
int p=59;
int main(){
	
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	long long mul=1,hash=0;
	
	for(int i=0;i<n;i++)
	{
		s[i]-='0';
	}
	
	for(int i=0;i<n;i++)
	{
		mul*=p;
		hash=hash*p+s[i];
	}
	
	long long old=hash;
	for(int i=0;i<=n;i++)
	{
		hash=hash*p-s[i]*mul+s[i];
		if(old==hash) 
		{
			printf("%d",i+1);
			return 0;
		}
	}
}
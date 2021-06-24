#include<bits/stdc++.h>
using namespace std;

unsigned long long s0,s1,s2,s3,sf;

int main(){
	
	long long n,m;
	scanf("%lld%lld",&n,&m);
	
	sf=n;
	
	for(int i=2;i<=m;i++)
	{
		sf+=s3;
		s3=s2;
		s2=s1;
		s1=s0;
		s0=sf/2;
	//	printf("%llu %llu %llu %llu %llu\n",s0,s1,s2,s3,sf);
	}
	printf("%llu",s0+s1+s2+s3+sf);
}

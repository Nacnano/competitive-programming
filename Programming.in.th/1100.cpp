#include<bits/stdc++.h>
using namespace std;

long long a[3][10];
long long b[3][10][10];
long long c[10][10][10];
int main(){
	
	int n;
	scanf("%d",&n);
	
	long long ans=0;
	while(n--)
	{
		char num[5];
		scanf("%s",num);
		
		for(int i=0;i<3;i++) num[i] -= '0';
		
		for(int i=0;i<3;i++)
			ans += a[i][num[i]]++;
			
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				for(int k=j+1;k<3;k++)
					if(j!=i && k!=i) ans -= b[i][num[j]][num[k]]++;
				
		ans += c[num[0]][num[1]][num[2]]++;
	}
	
	printf("%lld",ans);
}

/*
5
235
236
136
004
174

*/

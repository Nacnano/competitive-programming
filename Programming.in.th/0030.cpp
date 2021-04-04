#include<bits/stdc++.h>
using namespace std;

int main(){
	
	char a[1000010];
	scanf("%s",&a);
	
	int sum3=0,sum11=0;
	for(int i=0;a[i];i++)
	{
		if(i>0)
		{
			sum3 *= 10;
			sum11 *= 10;
		}
		
		sum3 += a[i]-'0';
		sum11 += a[i]-'0';
		
		sum3 %=3;
		sum11 %= 11;
	}
	printf("%d %d",sum3,sum11);
}

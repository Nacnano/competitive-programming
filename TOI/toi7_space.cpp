#include<bits/stdc++.h>
using namespace std;

char s[100];

int main(){
	
	int d;
	scanf("%d",&d);
	
	for(int i=1;i<=(1<<d);i++)
	{
		for(int j=0;j<d;j++)
		{
			if((1<<j)&i) s[j]='1';
			else s[j]='0';
		}
		
		for(int j=0;j<d;j++)
		{
			if(s[j]=='0')
			{
				printf("%s ",s);
				s[j]='1';
				printf("%s\n",s);
				s[j]='0';
			}	
		}
	}
}


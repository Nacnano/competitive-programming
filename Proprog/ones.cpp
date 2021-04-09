#include<bits/stdc++.h>
using namespace std;

bool have[10005];
int ones[10005];
void calc(int x)
{
	int num=1;
	int cnt=1;
	while(num!=0)
	{
		num = num*10 +1;
		num %=x;
		cnt++;
	}
	ones[x]=cnt;
	return;
}

int main(){

	ones[1]=1;
	
	int n;
	while(scanf("%d",&n) != EOF)
	{
		if(!ones[n]) calc(n);
		printf("%d\n",ones[n]);
	}
}

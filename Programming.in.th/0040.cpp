#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	scanf("%d",&n);
	while(n--)
	{
		char a[10000];
		scanf("%s",&a);
		int len=strlen(a);
		if(len == 1 && a[0] == '2') printf("T\n");
		else if((a[len-1] - '0')%2==0) printf("F\n");
		else printf("T\n");
	}
}

#include<bits/stdc++.h>
using namespace std;

char arr[105];

int k,a,b;
void solve(int lv,int win,int loss)
{
	if(win>=k || loss>=k)
	{
		for(int i=1;i<lv;i++) printf("%c ",arr[i]);
		printf("\n");
		return;
	}
	
	arr[lv]='W';
	solve(lv+1,win+1,loss);
	arr[lv]='L';
	solve(lv+1,win,loss+1);
}

int main(){
	
	scanf("%d%d%d",&k,&a,&b);
	solve(1,a,b);
}

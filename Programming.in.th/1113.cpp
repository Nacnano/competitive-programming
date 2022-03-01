#include<bits/stdc++.h>
using namespace std;

string s;
map<long long,int> mm;
int main(){
	
	int n, k, ans=0;
	cin >> n >> k;
	cin >> s;
	long long cnt=0;
	mm[0]=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='R') cnt+=k;
		else cnt-=1;
		if(mm.find(cnt)==mm.end()) mm[cnt]=i+1;
		else ans=max(ans,i+1-mm[cnt]);
	}
	printf("%d",ans);
}

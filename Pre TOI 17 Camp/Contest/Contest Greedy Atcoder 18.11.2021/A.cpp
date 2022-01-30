#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt=0,cnt2=0;
	for(int i=0;s[i];i++)
	{
		if(s[i]=='R') cnt++;
	}
	
	for(int i=0;i<cnt;i++)
	{
		if(s[i]=='R') cnt2++;
	}
	cout << cnt-cnt2;
}

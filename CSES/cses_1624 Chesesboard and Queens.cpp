#include<bits/stdc++.h>
using namespace std;

string s[10];
int ans=0;
vector<pair<int,int> > v;
void solve(int i)
{
	if(i==8)
	{
		ans++;
		return;
	}
	for(int j=0;j<8;j++)
	{
		if(s[i][j]=='*') continue;
		bool con=1;
		for(auto it: v)
		{
			if(abs(it.second-j)==abs(it.first-i) || it.second==j || it.first==i)
			{
				con=0;
				break;
			}
		}
		
		if(!con) continue;
		v.push_back({i,j});
		solve(i+1);
		v.pop_back();
	}
}

int main(){
	ios_base::sync_with_stdio; cin.tie(NULL);

	for(int i=0;i<8;i++) cin >> s[i];
	solve(0);
	cout << ans;
	return 0;
}

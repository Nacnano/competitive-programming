#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define f first
#define s second

const int p=1e9+7;
const int maxN=105;

void solve(){
	char t[maxN], s[15][15];
	int dp[maxN];
	map<int, pii> mm;
	pii back[maxN];
	cin >> t;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> s[i];
		int hash=0;
		for(int j=0;s[i][j];j++){
			hash*=256;
			hash+=int(s[i][j]);
			hash%=p;
		}
		mm[hash]={strlen(s[i]), i+1};
	}

	for(int i=0;i<=100;i++) dp[i]=1e9;

	int len=strlen(t);
	
	int hash=0;
	for(int i=0;i<10;i++){
		hash*=256;
		hash+=t[i];
		hash%=p;
		if(mm.find(hash)!=mm.end()){
			int l=mm[hash].f;
			int num=mm[hash].s;
			for(int j=0;j<i;j++){
				dp[j]=1;
				back[j]={0, num};
			}			
		}

	}

	for(int i=0;i<len;i++){
		int hash=0;
		for(int j=0;j<10 && i+j<len;j++){
			hash*=256;
			hash+=t[i+j];
			hash%=p;
			if(mm.find(hash)!=mm.end()){
				int l=mm[hash].f;
				int num=mm[hash].s;
				for(int k=i;k<=i+j;k++){
					if(dp[k]>dp[i]+1){
						dp[k]=dp[i]+1;
						back[k]={i, num};
					}
				}
						
			}
		}
	}
	if(dp[len-1]==1e9){
		cout << "-1\n";
	}
	else{
		cout << dp[len-1] << "\n";
		pii now=back[len-1];
		while(now.f>0){
			now=back[now.first-strlen(s[now.s-1])];
			cout << now.s << " " << now.f << "\n";
		}
		cout << back[0].s << " " << back[0].f << "\n";
	}
	
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	#endif

	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t=1;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define f first
#define s second

const ll p=1e9+7;
const int maxN=115;

void solve(){
	char t[maxN], s[15][15];
	int dp[maxN];
	map<ll, int> mm;
	pii back[maxN];
	cin >> t+1;
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> s[i]+1;
		ll hash=0;
		int len=strlen(s[i]);
		for(int j=1;s[i][j];j++){
			hash*=1ll*256;
			hash+=1ll*s[i][j];
			hash%=p;
		}
		mm[hash]=i;
	}

	for(int i=0;i<=105;i++) dp[i]=1e9;

	int len=strlen(t);
	ll hash=0;
	for(int i=1;i<=10;i++){
		hash*=1ll*256;
		hash+=1ll*t[i];
		hash%=p;
		if(mm.find(hash)!=mm.end()){
			int num=mm[hash];
			for(int j=1;j<=i;j++){
				dp[j]=1;
				back[j]={1, num};
			}			
		}
	}

	for(int i=0;i<=len;i++){
		ll hash=0;
		for(int j=1;j<=10 && i+j<=len;j++){
			hash*=1ll*256;
			hash+=1ll*t[i+j];
			hash%=p;
			if(mm.find(hash)!=mm.end()){
				int num=mm[hash];
				for(int k=i;k<=i+j;k++){
					if(dp[k]>dp[i]+1){
						dp[k]=dp[i]+1;
						back[k]={i+1, num};
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
		while(now.f>=1){
			cout << now.s << " " << now.f << "\n";
			now=back[now.f-1];
		}
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
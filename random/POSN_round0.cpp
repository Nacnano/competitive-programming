#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define f first
#define s second

const ll p=1e9+7;
const int maxN=200005;

map<char, pair<double, double> > mm;

void setup(){
	mm['A']={1, 6};
	mm['B']={6, 3};
	mm['C']={2, 2};
	mm['D']={9, 7};
	mm['E']={8, 1};
}

double dis(pii a, pii b){
	return sqrt((a.f-b.f)*(a.f-b.f)+(b.s-a.s)*(b.s-a.s));
}

void solve(){

	setup();
	double total=0;
	string s;
	cin >> s;
	for(int i=1;s[i];i++){
		total+=dis(mm[s[i]], mm[s[i-1]]);
	}
	cout << total << '\n';

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
}


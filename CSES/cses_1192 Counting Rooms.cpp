#include<bits/stdc++.h>
using namespace std;
const int mxn = 1005;
const int p =1e9+7;

int n, m;
string a[mxn];
int d[5][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

void dfs(int x, int y){

	for(int i=0;i<4;i++){
		int nx = x + d[i][0];
		int ny = y + d[i][1];

		if(nx<0 || nx>=m || ny<0 || ny>=n || a[ny][nx]=='#') continue;
		a[ny][nx] = '#';
		dfs(nx,ny);
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j] == '.') dfs(j, i), ans++;
		}
	}
	cout << ans;

	return 0;
}
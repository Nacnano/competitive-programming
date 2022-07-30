#include<bits/stdc++.h>
using namespace std;
const int maxN=1005, maxM=1005;
char back[maxN][maxM];
int dis[maxN][maxM], n, m;
pair<int,int> st, ed;
int di[5][2] = {{1,0}, {-1,0}, {0,-1}, {0,1}};
char mm[5] = {'U', 'D', 'L', 'R'};
string s [maxN];

void dfs(int x, int y){
	for(int i=0;i<4;i++){
		int nx=x+di[i][1], ny=y+di[i][0];
		if(nx<0 || ny<0 || nx>=m || ny>=n) continue;
		if(s[ny][nx]=='#') continue;
		if(dis[ny][nx]>dis[y][x]+1){
			// dis[ny][nx]=dis[y][x]+1;
			cout << x << " " << y << " " << nx << " " << ny << "\n";
			back[ny][nx]=mm[i];
			dfs(nx,ny);
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ios_base::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> s[i];
		for(int j=0;j<m;j++){
			if(s[i][j]=='A') st={i,j};
			else if(s[i][j]=='B') ed={i,j};
			dis[i][j]=1e9;
		}
	}
	dis[st.first][st.second]=0;
	dfs(st.second, st.first);

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout << dis[i][j] << " ";
		}
		cout << "\n";
	}
	// back[0][0]='C';
	// back[0][1]='D';
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			// cout << back[i][j] << " ";
		}
		cout << "\n";
	}

	if(dis[ed.first][ed.second]==1e9) cout << "NO";
	else{
		cout << "YES\n" << dis[ed.first][ed.second] << "\n";
		pair<int,int> now={ed.first, ed.second};
		vector<char> ans;
		while(now!=st){
			char now_back=back[now.first][now.second];
			ans.push_back(now_back);
			int nx=now.second, ny=now.first;
			if(now_back=='L') nx--;
			else if(now_back=='R') nx++;
			else if(now_back=='U') ny++;
			else if(now_back=='D') ny--;
			now={ny,nx};
		}
		for(int i=ans.size()-1;i>=0;i--) cout << ans[i];
	}

	return 0;
}
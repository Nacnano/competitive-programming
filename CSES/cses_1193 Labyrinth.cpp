#include<bits/stdc++.h>
using namespace std;
const int maxN=1005, maxM=1005;
char back[maxN][maxM];
int dis[maxN][maxM], n, m;
pair<int,int> st, ed;
int di[5][2] = {{1,0}, {-1,0}, {0,-1}, {0,1}};
char mm[5] = {'D', 'U', 'L', 'R'};
string s [maxN];

void bfs(int x, int y){
	dis[y][x]=0;
	queue<pair<int,int> > q;
	q.push({x,y});
	while(!q.empty()){
		int x=q.front().first, y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int nx=x+di[i][1], ny=y+di[i][0];
			if(nx<0 || ny<0 || nx>=m || ny>=n) continue;
			if(s[ny][nx]=='#') continue;
			if(dis[ny][nx]>dis[y][x]+1){
				dis[ny][nx]=dis[y][x]+1;
				back[ny][nx]=mm[i];
				q.push({nx,ny});
			}
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

	bfs(st.second, st.first);

	if(dis[ed.first][ed.second]==1e9) cout << "NO";
	else{
		cout << "YES\n" << dis[ed.first][ed.second] << "\n";
		pair<int,int> now={ed.first, ed.second};
		vector<char> ans;
		while(now!=st){
			char now_back=back[now.first][now.second];
			ans.push_back(now_back);
			int nx=now.second, ny=now.first;
			if(now_back=='L') nx++;
			else if(now_back=='R') nx--;
			else if(now_back=='U') ny++;
			else if(now_back=='D') ny--;
			now={ny,nx};
		}
		for(int i=ans.size()-1;i>=0;i--) cout << ans[i];
	}

	return 0;
}
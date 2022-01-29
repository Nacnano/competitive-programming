#include<bits/stdc++.h>
using namespace std;

int p[100010];
int cnt[100010];

int _find(int x)
{
	if(p[x]==x) return x;
	else return p[x]=_find(p[x]);
}
// I NEED TO GO FOR A MINUTES I GUESS? note afk at 20:59
// OH IDIDNT NOTE THAT I WAS BACK AT 20:08 I GUESS?

int main(){
	ios_base::sync_with_stdio(NULL); cin.tie(NULL);
	
	int n;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=1;i<=n;i++)
	{
		int l;
		scanf("%d",&l);
		while(l--)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			if(b>50)
			{
				int pa=_find(a);
				int pi=_find(i);
				
				p[pi]=pa;
				if(pi!=pa) cnt[pa]+=cnt[pi]+1;
			}
		
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,cnt[i]);
	printf("%d",ans);
	
	return 0;
}

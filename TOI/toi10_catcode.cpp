#include<bits/stdc++.h>
using namespace std;
#define P 1000007
char a[35];
char s[1000010];
int mm[P+10];
int cat[100010];
bool chk[100010];

int main(){
	
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int k,m;
	cin >> k >> m;
	for(int i=1;i<=k;i++)
	{
		cin >> a;
		int sum=0;
		for(int j=0;j<m;j++) sum=(sum<<1)+(a[j]-'0');
		
		int heap=1;
		int hash=sum%P;
		while(mm[hash])
		{
			hash+=heap;
			hash=hash%P;
			
			heap*=2;
			heap=heap%P;
		}
		
		mm[hash]=i;
		cat[i]=sum;
	}
	
	int n;
	cin >> n;
	while(n--)
	{
		int d;
		cin >> d;
		cin >> s;
		
		int sum=0;
		bool ok=1;
		for(int i=d-m;i<d;i++) sum=(sum<<1)+(s[i]-'0');
		
		int mul=(1<<(m-1));
		for(int i=d-m-1;i>=-1;i--)
		{
			int hash=sum%P;;
			int heap=1;
			while(mm[hash] && cat[mm[hash]]!=sum)
			{
				hash+=heap;
				hash=hash%P;
				
				heap*=2;
				heap=heap%P;
			}
			
			if(mm[hash] && cat[mm[hash]]==sum)
			{
				chk[mm[hash]]=1;
				ok=0;
			}
			
			if(i>=0) sum=(sum>>1)+(s[i]-'0')*mul;
		}
		
		if(ok==1) cout << "OK\n";
		else
		{
			for(int i=1;i<=k;i++)
			{
				if(chk[i]==1)
				{
					cout << i << " ";
					chk[i]=0;
				}
			}
			cout << "\n";	
		}
	}
	
}

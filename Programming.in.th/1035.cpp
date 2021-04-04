#include<bits/stdc++.h>
using namespace std;

int lp[2000050];
bool palin(char str[100])
{
	int len=strlen(str);
	for(int i=0;i<len/2;i++)
	{
		if(str[i]!=str[len-i-1]) return 0;
	}
	return 1;
}


int main(){
	
	vector<int> pr;
	for(int i=2;i<=2000000;++i)
	{
	    if(lp[i] == 0)
		{
	        lp[i] = i;
	        pr.push_back(i);
	    }
	    for(int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=2000000; ++j)
	        lp[i * pr[j]] = pr[j];
	}

	int n;
	scanf("%d",&n);
	for(auto p: pr)
	{
		if(p>=n)
		{
			char str[100];
			sprintf(str,"%d",p);
			if(palin(str))
			{
				printf("%d",p);
				break;
			}
			
		}
	}
}

#include <bits/stdc++.h>
using namespace std;

string str[5];
map<string,int> cnt;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    for(int i=0;i<4;i++)
    {
        map<string,bool> have;
        cin >> str[i];
        int len=str[i].length();
        for(int j=0;str[i][j];j++) if(str[i][j]>='A' && str[i][j]<='Z') str[i][j]+=32;

        for(int j=1;j<=len;j++)
        {
            for(int it1=0;it1+j<=len;it1++)
            {
               string strtmp=str[i].substr(it1,j);
               if(have.count(strtmp)==0)
               {
                   have[strtmp]=1;
                   cnt[strtmp]++;
               }     
           }
        }
    }

    int len=0;
    string ans;
    for(auto it:cnt)
    {
        if(it.second<3) continue;
        if(it.first.length()>len)
        {
            len=it.first.length();
            ans=it.first;
        }
        else if(it.first.length()==len && it.first < ans) ans=it.first;
    }
    cout << ans;
}
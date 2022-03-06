#include<bits/stdc++.h>
using namespace std;

map<string,string> mm;
map<string, bool> no;
vector<string> st;

int main(){

    int n;
    scanf("%d",&n);
    while(n--)
    {
        char s1[25],s2[25];
        scanf("%s %s",s1,s2);
        mm[s1]=s2;
        no[s2]=1;
        st.push_back(s1);
    }


    for(int i=0;i<(int)st.size();i++)
    {
        string now=st[i];
        if(no[now]) continue;
        while(1)
        {
            string tmp=now;;
            now=mm[now];
            mm.erase(tmp);
         //   cout << " now " << now << " " << tmp << "\n";
            if(mm.find(now)==mm.end())
            {
                mm[st[i]]=now;
                mm.erase(now);
                break;
            }
        }
    }
    printf("%d\n",mm.size());
    for(auto x:mm)
    {
        cout << x.first << " " << x.second << "\n";
    }

}

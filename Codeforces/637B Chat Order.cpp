#include<bits/stdc++.h>
using namespace std;

map<string,bool> mm;
char s[200005][15];
int main(){

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",&s[i]);
    }

    for(int i=n-1;i>=0;i--)
    {
        if(!mm[s[i]])
        {
            printf("%s\n",s[i]);
            mm[s[i]]=1;
        }

    }

}

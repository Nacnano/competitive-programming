#include<bits/stdc++.h>
using namespace std;

char s[5010];
int col[5010],row[5010];

int main(){

    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%s",&s);
        for(int j=0;j<m;j++)
        {
            col[j]+=s[j]-'0';
            row[i]+=s[j]-'0';
        }
    }

    int cnt=0;
    for(int i=0;i<n;i++)
        if(row[i]==m) cnt++;

    for(int i=0;i<m;i++)
        if(col[i]==n) cnt++;

    printf("%d",cnt);
}

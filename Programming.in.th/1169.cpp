#include<bits/stdc++.h>
using namespace std;

int main(){
    char s[205];
    scanf("%s",s);

    int cnt=0,ans=0;
    for(int i=0;s[i];i++)
    {
        if(s[i]=='(') cnt++;
        else cnt--;

        if(cnt<0) ans++,cnt=0;
    }
    printf("%d",ans+cnt);
}

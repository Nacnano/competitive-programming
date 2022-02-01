#include<bits/stdc++.h>
using namespace std;

char s[1000005];

int main(){

    scanf("%s",s);
    int ans=0;
    for(int i=0;s[i];i++)
    {
        if(s[i]=='0') ans+=2;
        else if(s[i]=='4') ans++;
        else if(s[i]=='6') ans++;
        else if(s[i]=='8') ans+=2;
        else if(s[i]=='9') ans++;
    }
    printf("%d",ans);
}

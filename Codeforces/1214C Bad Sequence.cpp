#include<bits/stdc++.h>
using namespace std;

char s[200010];

int main(){

    int n;
    scanf("%d",&n);
    scanf("%s",s);

    if(n%2!=0)
    {
        printf("No");
        return 0;
    }

    int cnt=0;
    for(int i=0;s[i];i++)
    {
        if(s[i]=='(') cnt++;
        else cnt--;
        if(cnt<-1)
        {
            printf("No");
            return 0;
        }
    }

    if(cnt!=0) printf("No");
    else printf("Yes");

    return 0;
}

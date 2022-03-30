#include<bits/stdc++.h>
using namespace std;

char s[2005];
bool palin(char s[2010],int l,int r)
{
    if(s[l]!=s[r]) return 0;
    if(l==r) return 1;
    if(l+1==r && s[l]==s[r]) return 1;
    palin(s,l+1,r-1);

}
int main(){

    scanf("%s",s);
    int len=strlen(s);
    if(palin(s,0,len-1)) printf("YES");
    else printf("NO");
}

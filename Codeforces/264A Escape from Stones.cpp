#include<bits/stdc++.h>
using namespace std;

vector<int> v(2000005,0);
char s[2000005];

int main(){

    scanf("%s",s);
    int len=strlen(s);
    int r=len,l=1;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='l') v[r--]=i+1;
        else v[l++]=i+1;

    }
    for(int i=1;i<=len;i++) printf("%d\n",v[i]);
}

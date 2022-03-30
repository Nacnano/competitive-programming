#include<bits/stdc++.h>
using namespace std;

char x[2000010];

int main(){

    int hsh[260];
    char a[30],b[30];
    scanf("%s",a);
    scanf("%s",b);

    for(int i=0;i<26;i++)
    {
        hsh[a[i]]=b[i];
    }

    scanf("%s",x);
    for(int i=0;x[i];i++)1
    {
        printf("%c",hsh[x[i]]);
    }
}

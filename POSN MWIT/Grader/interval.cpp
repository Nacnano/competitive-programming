#include<bits/stdc++.h>
using namespace std;

const int range=200000;
const int pl=100000;
int in[range+10],out[range+10];

int main(){

    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        in[a+pl]++;
        out[b+pl]++;
    }

    int ans=0,cnt=0,chk=0;
    for(int i=0;i<=200005;i++)
    {
        cnt+=in[i]-out[i];

        if(cnt!=0) chk=1;

        if(cnt==0 && chk==1)
        {
            ans++;
            chk=0;
        }
    }
    printf("%d",ans);
}

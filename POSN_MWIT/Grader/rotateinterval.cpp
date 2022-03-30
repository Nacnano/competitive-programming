#include<bits/stdc++.h>
using namespace std;

int main(){

    int q;
    scanf("%d",&q);
    while(q--)
    {
        char s[1005];
        scanf("%s",s);
        int len=strlen(s);

        int n,k;
        scanf("%d%d",&n,&k);
        k%=n;
        for(int i=0;i<len;i+=n)
        {
            for(int j=0;j<n;j++)
            {
                printf("%c",s[i+(j-k+n)%n]);
            }
        }
        printf("\n");
    }
}

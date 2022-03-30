#include<bits/stdc++.h>
using namespace std;

int n,r,k;
int tmp[15];
int fac[15];
bool used[15];
int cnt=0;
void per(int lv)
{
    if(lv==r)
    {
        cnt++;
        if(cnt==k)
        {
            for(int i=0;i<r;i++)
            {
                printf("%d ",tmp[i]);
            }
            exit(0);
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(used[i]==0)
            {
                tmp[lv]=i;
                used[i]=1;
                per(lv+1);
                used[i]=0;
            }
        }
    }
}

int main(){

    scanf("%d%d%d",&n,&r,&k);


    per(0);

}

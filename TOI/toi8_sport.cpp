#include<bits/stdc++.h>
using namespace std;
int n,a,b;
char tmp[1005];
void spo(int w,int l,int lv)
{
    if(w>n || l>n) return;

    if(w==n || l==n)
    {
        for(int i=0;i<lv;i++)
        {
            printf("%c ",tmp[i]);
        }
        printf("\n");
        return;
    }
    tmp[lv]='W';
    spo(w+1,l,lv+1);
    tmp[lv]='L';
    spo(w,l+1,lv+1);

}

int main(){


    scanf("%d%d%d",&n,&a,&b);
    spo(a,b,0);
}

#include<bits/stdc++.h>
using namespace std;

long long hsh[200];
long long pr1=1e9+7,pr2=98765321;

int main(){

    hsh['A']=pr2;
    for(int i=1;i<=30;i++)
    {
        hsh['A'+i]=hsh['A'+i-1]*pr1;
    }

    char a[2010],b[2010];
    scanf("%s",a);
    scanf("%s",b);
    int lena=strlen(a),lenb=strlen(b);
    int mn=min(lena,lenb);
    for(int l=mn;l>=1;l--)
    {
        map<long long,bool> mm;
        long long sum=0;
        for(int i=0;i<l;i++)
        {
            sum+=hsh[a[i]];
        }
        mm[sum]=1;
        for(int i=l;i<lena;i++)
        {
            sum-=hsh[a[i-l]];
            sum+=hsh[a[i]];
            mm[sum]=1;
        }

        sum=0;
        for(int i=0;i<l;i++)
        {
            sum+=hsh[b[i]];
        }
        if(mm[sum])
        {
            printf("%d",l);
            return 0;
        }

        for(int i=l;i<lenb;i++)
        {
            sum-=hsh[b[i-l]];
            sum+=hsh[b[i]];
            if(mm[sum])
            {
                printf("%d",l);
                return 0;
            }
        }
    }
    printf("0");
    return 0;
}

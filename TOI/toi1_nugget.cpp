#include<bits/stdc++.h>
using namespace std;

bool hsh[150];

int main(){

    hsh[0]=1;
    for(int i=0;i<=100;i++)
    {
        if(hsh[i]) hsh[i+6]=1,hsh[i+9]=1,hsh[i+20]=1;;
    }

    int n;
    scanf("%d",&n);
    if(n<6)
    {
        printf("no");
        return 0;
    }
    else
    {
        for(int i=6;i<=n;i++)
        {
            if(hsh[i])printf("%d\n",i);
        }
    }

}




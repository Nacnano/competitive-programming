#include<bits/stdc++.h>
using namespace std;

const int mxn=1000000;
int arr[mxn+5];
int r[mxn+5],l[mxn+5];

int main(){

    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);

    n--;
    while(n--)
    {
        int a,b;
        scanf("%d%d",&a,&b);

        if(!r[b])
        {
            while(1)
            {
                if(l[b]==0)
                {
                    l[b]=a;
                    break;
                }
                b=l[b];

            }
        }
        else if(!l[a])
        {
            while(1)
            {
                if(r[a]==0)
                {
                    r[a]=b;
                    break;
                }
                a=r[a];
            }
        }
    }

    //suppose that st=1;
    int st=1;
    while(!l[st])
    {
        st=l[st];
    }

   int now=st;
   while(!r[now])
   {
       printf("%d ",arr[now]);
       now=r[now];
       printf("now %d\n",now);
   }

}


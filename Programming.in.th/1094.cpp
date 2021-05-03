#include<bits/stdc++.h>
using namespace std;

int a[10];
bool sorted(int a[10])
{
    for(int i=1;i<5;i++)
    {
        if(a[i]>a[i+1]) return 0;
    }
    return 1;
}

void print()
{
    for(int i=1;i<=5;i++) printf("%d ",a[i]);
    printf("\n");
}

int main(){

    for(int i=1;i<=5;i++) scanf("%d",&a[i]);

    while(!sorted(a))
    {
        if(a[1]>a[2]) swap(a[1],a[2]),print();
        if(a[2]>a[3]) swap(a[2],a[3]),print();
        if(a[3]>a[4]) swap(a[3],a[4]),print();
        if(a[4]>a[5]) swap(a[4],a[5]),print();
    }
}

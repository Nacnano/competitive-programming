#include<bits/stdc++.h>
using namespace std;

int main(){

    char c;
    scanf("%c",&c);
    int n;
    scanf("%d",&n);

    printf("%c",((c-'A'+n)%26+26*10)%26+'A');
}

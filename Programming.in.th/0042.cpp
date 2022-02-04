#include<iostream>
#include<stdio.h>
using namespace std ;
int main(){
  int n;
  cin >> n ;
  int i,j;
  int x;
  long double y ;
  for(i=0;i<n;i++){
    cin >> x ;
    y = 1;
    for(j=1;j<=x;j++) y *= 2 ;
    printf("%.0Lf\n",y) ;
  }
}


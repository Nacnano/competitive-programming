#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int value;
    struct node *next;
};

int main(){

    node* p=NULL;
    node* q=NULL;

    p = new node;
    q = new node;

    p->value = 10;
    q->value = 20;

    p->next = q;
    q->next=NULL;

    node* x=p;
    while(x!=NULL)
    {
        printf("%d\n",x->value);
        x=x->next;
    }
}

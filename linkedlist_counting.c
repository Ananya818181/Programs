#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*a,*b,*c;
void main()
{
    a=(struct node*)malloc(sizeof(struct node));
    b=(struct node*)malloc(sizeof(struct node));
    c=(struct node*)malloc(sizeof(struct node));
    struct node*start;
    start->next=a;
    a->data=4;
    a->next=b;
    b->data=5;
    b->next=c;
    c->data=6;
    c->next=NULL;
    start=a;
    int c=0;
    while(start!=NULL)
    {
        printf("%d \n",start->data);
        start=start->next;
        c++;
    }
    printf("the no. of nodes are %d ",c );
}
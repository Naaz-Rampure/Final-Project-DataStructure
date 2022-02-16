#include<stdio.h>
#include<stdlib.h>

struct node{
int info;
struct node* lptr;
struct node* rptr;
struct node* link;
};

void traverse(struct node*);
struct node *insertatfirst(struct node*,int);
struct node *delete(struct node*);
void main(){
struct node * head;
struct node *second;
struct node *third;


head=(struct node *)malloc(sizeof(struct node));
second=(struct node *)malloc(sizeof(struct node));
third=(struct node *)malloc(sizeof(struct node));

head->info=5;
head->link=second;

second->info=7;
second->link=third;

third->info=10;
third->link=head;

traverse(head);

head=insertatfirst(head,50);
printf("after insertion\n");
traverse(head);
head=delete(head);
printf("After deletion:\n");
traverse(head);
}

void traverse(struct node* head){
struct node* first=head;
do{
printf("element:%d\n",first->info);
first=first->link;
}while(first!=head);
}

struct node* insertatfirst(struct node* head,int data){
struct node* first=(struct node*)malloc(sizeof(struct node));
first->info=data;
struct node* p= head -> link;
while(p->link!=head){
p=p->link;
}
first->info=data;
p->link=first;
first->link=head;
return head;
}

struct node* delete(struct node* head){
struct node* first=head;
struct node * first1;
while(first->link!=head){
first1=first;
first=first->link;

first1->link=first->link;
free(first);
return head;
}
}




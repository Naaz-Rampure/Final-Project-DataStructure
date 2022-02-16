#include<stdio.h>
#include<stdlib.h>

struct node{
int info;
struct node *link;
};


void traverse(struct node *);

struct node* insertatfirst(struct node *,int);
struct node* insertatend(struct node *,int);
struct node* insertatindex(struct node *,int,int);
struct node* delete(struct node*);

int main(){
struct node *head;
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
third->link=NULL;

//count node
struct node* temp=head;
int count=0;
while(temp!=0){
temp=temp->link;
count++;
}
printf("total no. of node %d\n",count);



traverse(head);
head=insertatfirst(head,50);
printf("update at 1st index\n");
traverse(head);

head=insertatend(head,71);
printf("update at end\n");
traverse(head);

head=insertatindex(head,30,2);
printf("update in between\n");
traverse(head);

head=delete(head);
printf("linklist after deletion\n");
traverse(head);
return 0;



}
void traverse(struct node * first){
while(first!=NULL){
printf("element: %d\n",first->info);
first=first->link;
}
}

struct node* insertatfirst(struct node *head,int data){
struct node * first=(struct node *)malloc(sizeof(struct node));
first->link=head;
first->info=data;
return first;
}


struct node* insertatend(struct node *head,int data){
struct node* first=(struct node*)malloc(sizeof(struct node));
struct node* p=head;
while(p->link!=NULL){
p=p->link;
}
first->info=data;
p->link=first;
first->link=NULL;
return head;
}

struct node* insertatindex(struct node *head,int data,int index){
struct node * first=(struct node *)malloc(sizeof(struct node));
struct node * p= head; //temperory pointer
int i=0;
while(i!=index-1)
{
p=p->link;
i++;
}
first->info=data;
first->link=p->link;
p->link=first;
return head;

}


//delete
struct node* delete(struct node* head){
struct node* first=head;
head=head->link;
free(first);
return head;
}





#include<stdio.h>
#include<stdlib.h>

struct node{
char data;
struct node *left;
struct node *right;
};

void priorder(struct node*);
void postorder(struct node*);
void inorder(struct node*);

void main(){
struct node *a,*b,*c,*d,*e,*f,*g,*ptr;
a=(struct node *)malloc(sizeof(struct node));
b=(struct node *)malloc(sizeof(struct node));
c=(struct node *)malloc(sizeof(struct node));
d=(struct node *)malloc(sizeof(struct node));
e=(struct node *)malloc(sizeof(struct node));
f=(struct node *)malloc(sizeof(struct node));
g=(struct node *)malloc(sizeof(struct node));

ptr=a;
a->data='A';
a->left=b;
a->right=d;

b->data='B';
b->left=c;
b->right=NULL;

c->data='C';
c->left=NULL;
c->right=NULL;

d->data='D';
d->left=e;
d->right=g;

e->data='E';
e->left=NULL;
e->right=f;

f->data='F';
f->left=NULL;
f->right=NULL;

g->data='G';
g->left=NULL;
g->right=NULL;


printf("After preorder operation\n");
priorder(ptr);
printf("\nAfter inorder operation\n");
inorder(ptr);
printf("\nAfter postorder operation\n");
postorder(ptr);

}


void priorder(struct node *ptr){

if(ptr==NULL)
printf("Empty tree");
else{
printf("%c",ptr->data);
if(ptr->left!=NULL){
postorder(ptr->left);
}
if(ptr->right!=NULL){
postorder(ptr->right);
}
}

}


void inorder(struct node* ptr){
if(ptr==NULL)
printf("Empty tree");
else{
if(ptr->left!=NULL){
inorder(ptr->left);
}
printf("%c",ptr->data);
if(ptr->right!=NULL){
inorder(ptr->right);
}

}
}

void postorder(struct node *ptr){

if(ptr==NULL)
printf("Empty tree");
else{
if(ptr->left!=NULL){
postorder(ptr->left);
}
if(ptr->right!=NULL){
postorder(ptr->right);
}
}

printf("%c",ptr->data);
}


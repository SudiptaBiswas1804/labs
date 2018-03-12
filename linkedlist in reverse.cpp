#include <iostream>
using namespace std;

struct node{
int data;
node *next;
node *prev;
};

class linkedlist{
private:
node *head;
node *tail;
public:
linkedlist(){
head==NULL;
tail==NULL;
}

void addnode(int n){
node *temp=new node;
temp->data=n;
temp->next=NULL;
temp->prev=NULL;
if(head==NULL){
head=temp;
}
else if(head!=NULL){
temp->next=temp;
tail=temp;
}
}

int count(){
int length=0;
node *temp=new node;
temp=head;
if(head!=NULL){
while(temp!=NULL){
temp=temp->next;
length++;
}
}
return length;
}

void reverse(){
node *temp=new node;
node *c=new node;
node *p=new node;
node *a=new node;
int l=count();
p=head;
for(int i=0; i<l/2; i++){
p=p->next;
}
while(temp<p && c>p){
for(int i=0; i<l; i++){
temp=head;
c=tail;
for(int j=0; j<(l-i)-1; j++){
if(temp->data>c->data){
a->data=temp->data;
temp->data=c->data;
c->data=a->data;
}
temp=temp->next;
c=c->prev;}
}
}
}

};

int main(){
int i,n,n2;
linkedlist l;
l.addnode(2);
l.addnode(3);
l.addnode(4);
l.addnode(5);
l.count();
l.reverse();
return 0;
}

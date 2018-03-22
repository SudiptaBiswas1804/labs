#include <iostream>
using namespace std;

class node{
public:
int data;
node *left;
node *right;
};

class Binarytree{

public:
node *root;
Binarytree(){
root=NULL;
}

void insert(node *tree, int n){
 node *temp=new node;temp->data=n; temp->left=NULL; temp->right=NULL;
 
 if(tree->data>temp->data){
  if(tree->left==NULL){
   tree->left=temp;
  }
 else {
  while(tree!=NULL){
   if(tree->data>temp->data){
    tree->left=temp;
    }
   else
    tree->right=temp;
    }
 }
}

 else //if(tree->data<temp->data){
{
  if(tree->right==NULL){
   tree->right=temp;
  }
  else {
   while(tree!=NULL){
    if(tree->data<temp->data){
     tree->right=temp;
    }
    else
     tree->left=temp;
    }
  }
 }
}

void disp(node *temp){
 if(temp==NULL) return;
  else{ 
   disp(temp->left);
   cout<<temp->data;
   disp(temp->right);
}
} 
};

int main(){
Binarytree bt;
bt.insert(bt.root,10);
bt.insert(bt.root,2);
bt.insert(bt.root,3);
bt.insert(bt.root,23);
bt.disp(bt.root);
return 0;
}




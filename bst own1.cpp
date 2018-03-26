#include <iostream>
using namespace std;

class BST{
	struct node{
		int data;
		node* left;
		node* right;
	};
	
	node* root;
	
	node* insert(int x, node* temp){
		if(temp==NULL){
			temp=new node;
			temp->data=x;
			temp->left=NULL;
			temp->right=NULL;
		}
		else if(x<temp->data){
			temp->left=insert(x,temp->left);
		}
		else if(x>temp->data){
			temp->right=insert(x,temp->right);
		}
    return temp;
	}
	
	void inorder(node *temp){
		if(temp==NULL){
			return 0;
		}
		else{
			inorder(t->left);
			cout<<t->data<<"->";
			inorder(t->right);
		}
		}
		
		public:
		BST(){
			root=NULL;
		}
		
		void insert(root){
			root=insert(x,root);
		}
		
		void inorder(){
			inorder(root);
			cout<<endl;
		}

};

int main(){
	BST bst;
	bst.insert(10);
	bst.insert(20);
	bst.insert(30);
	bst.insert(40);
	bst.insert(50);
	bst.inorder();
	}

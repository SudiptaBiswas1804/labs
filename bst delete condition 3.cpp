#include<iostream>
using namespace std;

 struct node
    {
        int data;
        node* left;
        node* right;
        node* parent;
    };
    
class BST
{
   public:

    node* root;
    node* insert(int x, node* temp)
    {
        if(temp == NULL)
        {
            temp = new node;
            temp->data = x;
            temp->left = temp->right = NULL;
            
        }
        else if(x < temp->data)
            { temp->left = insert(x, temp->left);
            temp->left->parent = temp;
            }
        else if(x > temp->data)
            { temp->right = insert(x, temp->right);
            temp->right->parent = temp;
            }
        return temp;
    }
    node* search(int x, node* temp)
    {
      if(temp == NULL)
           return NULL;
      else if(x==temp->data)
           return temp;     
      else if(x<temp->data)
           return search(x,temp->left);
      else if(x>temp->data)
           return search(x,temp->right);
    }
    node* parent(int x, node* temp){
    	if(temp==NULL){
    		return NULL;
    	}
    	else if(x==temp->data){
    		if(temp->parent==NULL){
    			return temp;
    		}
    		else if(temp->parent!=NULL){
    	                        return temp->parent;
    		}
    	}
    	
            else if(x<temp->data)
            return parent(x, temp->left);
            
            else if(x>temp->data)
            return parent(x, temp->right);
    	}
    
    void inorder(node* temp)
    {
        if(temp == NULL)
            return;
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
    node* min(node *temp){
    	if(temp==NULL){
    		return NULL;
    	}
    	else if(temp->left==NULL){
    		return temp;
    	}
    	else if(temp->left!=NULL){
    		return min(temp->left);
    	}
    }  
    node* deletion(int x, node* temp)
   {
     if(temp == NULL)
           return NULL;
     else if(x<temp->data)
           deletion(x,temp->left);
     else if(x>temp->data)
           deletion(x,temp->right);
   else if(x==temp->data)
     {
     	if(temp->left== NULL && temp->right == NULL){
     		if(temp->parent->left==temp){
     			temp->parent->left=NULL;
     		}
     		else if(temp->parent->right==temp){
     			temp->parent->right=NULL;
     		}
     		delete temp;
     		}
     	else if(temp->left== NULL || temp->right == NULL){
     		if(temp->parent->left==temp){
     			if(temp->left!=NULL){
     			temp->parent->left=temp->left;
     			temp->left->parent=temp->parent;
     			}
     			else if(temp->right!=NULL){
     			temp->parent->left=temp->right;
     			temp->right->parent=temp->parent;
     			}
     		}
     		else if(temp->parent->right==temp){
     			if(temp->left!=NULL){
     				temp->parent->left=temp->left;
     				temp->left->parent=temp->parent;
     			}
     			else if(temp->right!=NULL){
     				temp->parent->right=temp->right;
     				temp->right->parent=temp->parent;
     			}
     		}
     		delete temp;
     	}
     	else if(temp->left!=NULL && temp->right!=NULL){
     		node* temp1=min(temp->right);
     		temp->data=temp1->data;
     		if(temp1->left==NULL && temp1->right==NULL){
     			if(temp1->parent->left==temp1){
     			temp1->parent->left=NULL;
     		}
     		            else if(temp1->parent->right==temp1){
     			temp1->parent->right=NULL;
     		}
     		delete temp1;
     		}
     		else if(temp1->left==NULL || temp1->right==NULL){
     			if(temp1->parent->left==temp1){
     			if(temp1->left!=NULL){
     			temp1->parent->left=temp1->left;
     			temp1->left->parent=temp1->parent;
     			}
     			else if(temp1->right!=NULL){
     			temp1->parent->left=temp1->right;
     			temp1->right->parent=temp1->parent;
     			}
     		}
     		else if(temp1->parent->right==temp1){
     			if(temp1->left!=NULL){
     				temp1->parent->left=temp1->left;
     				temp1->left->parent=temp1->parent;
     			}
     			else if(temp1->right!=NULL){
     				temp1->parent->right=temp1->right;
     				temp1->right->parent=temp1->parent;
     			}
     		}
     		delete temp1;
     		}
     	}
     		     	} 
     }
   
   
   
    BST()
    {
        root = NULL;
    }
    
     void insert(int x)
    {
        root = insert(x, root);
    }
 void display()
    {
        inorder(root);
        cout << endl;
    }
 node* search(int x)
    {   
       node *temp=search(x,root);
       return temp;
       
    }
    node* parent(int x){
    	 node*ti=parent(x,root);
    	 return ti;
    }
    void deletion(int x)
   {
      deletion(x,root);
   }

};
    
int main()
{
    BST t;
    t.insert(10);
    t.insert(8);
    t.insert(9);
    t.insert(7);
    t.insert(50);
    t.insert(55);
    t.display();
    node * temp =t.search(8);
    cout << temp -> data;
    cout<<endl;
    t.deletion(10);
    t.display();
    node* ti= t.parent(8);
    cout<<ti->data;
    cout<<endl;
}


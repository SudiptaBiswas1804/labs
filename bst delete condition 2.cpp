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
     		}
     	if(temp->left== NULL || temp->right == NULL){
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
     	}
     		
     	delete temp;		
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
    t.insert(50);
    t.display();
    node * temp =t.search(8);
    cout << temp -> data;
    cout<<endl;
    t.deletion(8);
    t.display();
    node* ti= t.parent(9);
    cout<<ti->data;
    cout<<endl;
}

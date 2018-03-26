#include<iostream>
using namespace std;

class BST
{
    struct node
    {
        int data;
        node* left;
        node* right;
    };

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
            temp->left = insert(x, temp->left);
        else if(x > temp->data)
            temp->right = insert(x, temp->right);
        return temp;
    }
    void inorder(node* temp)
    {
        if(temp == NULL)
            return;
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
    public:
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
};
    int main()
{
    BST t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.display();
}

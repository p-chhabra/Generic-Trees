#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BTNode
{
public:
    T data;
    BTNode<T> * left;
    BTNode<T> * right;

    BTNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BTNode()
    {
        delete left;
        delete right;
    }
};

class BST
{
   private:
   ///BFS
   void printTree(BTNode<int> * root)
   {
       if(!root) return;
       queue<BTNode<int>*> q;
       q.push(root);

       while(!q.empty())
       {
           BTNode<int> * f = q.front();
           q.pop();
           cout<<f->data<<": ";

           if(f->left){
            cout<<"L"<<f->left->data<<" ";
            q.push(f->left);
           }

           if(f->right){
            cout<<"R"<<f->right->data<<" ";
            q.push(f->right);
           }
           cout<<endl;
       }
   }

   bool hasDataHelper(BTNode<int> * root, int data)
   {
       if(!root) return false;
       if(root->data == data){
        return true;
       }

       if(data < root->data){
        hasDataHelper(root->left, data);
       }
       else if(data > root->data){
        hasDataHelper(root->right, data);
       }
   }

   BTNode<int> * insert(BTNode<int> * node, int data)
   {
       if(!node){
        BTNode<int> * n = new BTNode<int>(data);
        return n;
       }

       if(data < node->data){
        node->left = insert(node->left, data);
       }
       else{
        node->right = insert(node->right ,data);
       }
       return node;
   }

   public:
    BTNode<int> * root;

    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        delete root;
    }

    void insertData(int data)
    {
        root = insert(root, data);
    }

    void deleteData()
    {

    }

    bool hasData(int data)
    {
        return hasDataHelper(root, data);
    }

    void print()
    {
        printTree(root);
    }
};

//Sample BST - 10 5 15 3 7 -1 18 -1 -1 -1 -1 -1 -1 -1 -1

int main()
{
    BST b;
    b.insertData(10);
    b.insertData(13);
    b.insertData(5);
    b.insertData(17);
    b.insertData(8);
    b.insertData(9);
    b.insertData(3);
    b.print();
}

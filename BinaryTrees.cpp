#include <iostream>
#inlcude <queue>
using namespace std;

template <typename T>
class BTNode
{
    public:
    T data;
    BTNode * left;
    BTNode * right;

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

void printRecursive(BTNode<int> * root)
{
    if(!root) return;
    cout<<root->data<<": ";
    if(root->left!=NULL)
    {
        cout<<"L"<<root->left->data<<"  ";
    }
    if(root->right!=NULL)
    {
        cout<<"R"<<root->right->data<<"  ";
    }
    cout<<endl;
    printRecursive(root->left);
    printRecursive(root->right);
}

///RECURSIVE INPUT
//Very bad way of giving input since we have to keep track of the recursive calls
//We should use LevelWise input approach instead
BTNode<int> * InputRecursive()
{
    int rootData;
    cout<<"Enter data: ";
    cin>>rootData;
     if(rootData == -1)
     {
         return NULL;
     }
     BTNode<int> * root = new BTNode<int>(rootData);
     cout<<"Enter the left child of "<<root->data<<endl;
     root->left = InputRecursive();
     cout<<"Enter the right child of "<<root->data<<endl;
     root->right = InputRecursive();

     return root;
}

///LEVEL WISE INPUT
//A Better and more comfortable way to take input
BTNode * inputLevelWise()
{
    int rootData;
    cout<<"Enter the value of root: ";
    cin>>rootData;
    if(data == -1)
    {
        return NULL;
    }
    BTNode<int> * root = new BTNode<int>(rootData);

    queue<BTNode<int>> q;
    q.push(root);

    while(!q.empty())
    {
        BTNode<int> * f = q.front();
        q.pop();

        int left,right;
        cout<<"Enter left child of "<<f->data<<" ";
        cin>>left;
        q.push(left);
        f->left = left;
        cout<<"Enter the right child of "<<f->data<<" ";
        cin>>right;
        q.push(right);


    }
}


int main()
{
    BTNode<int> * root = InputRecursive();
    cout<<endl;
    printRecursive(root);

    delete root;

    return 0;
}

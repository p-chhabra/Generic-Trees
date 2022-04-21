#include <iostream>
#include <queue>
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
BTNode<int> * inputLevelWise()
{
    int rootData;
    cout<<"Enter the value of root: ";
    cin>>rootData;
    BTNode<int> * root = new BTNode<int>(rootData);

    queue<BTNode<int>*> q;
    q.push(root);

    while(!q.empty())
    {
        BTNode<int> * f = q.front();
        q.pop();

        int left,right;
        cout<<"Enter left child of "<<f->data<<": ";
        cin>>left;
        if(left != -1)
        {
            BTNode<int> * child = new BTNode<int>(left);
            q.push(child);
            f->left = child;
        }
        cout<<"Enter the right child of "<<f->data<<": ";
        cin>>right;
        if(right != -1)
        {
            BTNode<int> * child = new BTNode<int>(right);
            q.push(child);
            f->right = child;
        }


    }
    return root;
}

void printLevelWise(BTNode<int> * root)
{
    if(!root)
    {
        cout<<"Tree does not exist!"<<endl;
        return;
    }

    queue<BTNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        BTNode<int> * f = q.front();
        q.pop();
        cout<<f->data<<": ";
        if(f->left)
        {
            cout<<"L"<<f->left->data<<" ";
            q.push(f->left);
        }
        if(f->right)
        {
            cout<<"R"<<f->right->data<<" ";
            q.push(f->right);
        }
        cout<<endl;
    }
}

///Iterative Method || Level Order Traversal
int countTreeNodes(BTNode<int> * root)
{
    if(!root)
    {
        cout<<"Tree does not exist"<<endl;
        return -1;
    }

    queue<BTNode<int>*> q;
    q.push(root);

    int count = 1;
    while(!q.empty())
    {
        BTNode<int> * f = q.front();
        q.pop();

        if(f->left)
        {
            count++;
            q.push(f->left);
        }
        if(f->right)
        {
            count++;
            q.push(f->right);
        }
    }
    return count;
}


///Recursive Method
int countTreeNodesRec(BTNode<int> * root)
{
    if(!root)
    {
        return -1;
    }
    int count = 1;

    if(root->left){
        count = count + countTreeNodesRec(root->left);
    }
    if(root->right){
        count = count + countTreeNodesRec(root->right);
    }
    return count;
}

///InOrder Traversal print
void printInorder(BTNode<int> * root)
{
    if(!root){
        return;
    }

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int maxDepthBT(BTNode<int> * root)
{
    if(!root) return 0;

    int maxHeight = 0;

    if(root->left){
        int height = maxDepthBT(root->left);
        if(maxHeight<height){
            maxHeight = height;
        }
    }
    if(root->right){
        int height = maxDepthBT(root->right);
        if(maxHeight<height){
            maxHeight = height;
        }
    }
    return maxHeight + 1;
}

//Test Binary Tree - 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

int main()
{
    //BTNode<int> * root = InputRecursive();
    BTNode<int> * root = inputLevelWise();
    cout<<endl;
    //printRecursive(root);
    printLevelWise(root);

    //cout<<"Number of Nodes: "<<countTreeNodesRec(root)<<endl;
    cout<<"Number of Nodes: "<<countTreeNodes(root)<<endl;
    cout<<endl;
    printInorder(root);
    cout<<endl;

    cout<<maxDepthBT(root);

    delete root;

    return 0;
}

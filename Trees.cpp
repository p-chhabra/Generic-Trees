#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class treeNode
{
public:
    T data;
    vector<treeNode<T>*> children;

    treeNode(T data)
    {
        this->data = data;
    }
};

treeNode<int> * takeInput()
{
    int rootData;
    cout<<"Enter data: ";
    cin>>rootData;

    treeNode<int> * root = new treeNode<int>(rootData);
    int n;
    cout<<"Enter number of children of "<<rootData<<": ";
    cin>>n;

    for(int i =0; i<n; i++)
    {
        treeNode<int> * t = takeInput();
        root->children.push_back(t);
    }
    return root;
}

void printTree(treeNode<int> * root)
{
    if(!root) return;

    cout<<root->data<<": ";
    for(int i = 0; i<root->children.size(); i++)
    {
        cout<<root->children[i]->data<<" ,";
    }
    cout<<endl;

    for(int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

int main()
{
    /*
    treeNode<int> * root = new treeNode<int>(1);
    treeNode<int> * n1 = new treeNode<int>(2);
    treeNode<int> * n2 = new treeNode<int>(3);
    treeNode<int> * n3 = new treeNode<int>(4);
    treeNode<int> * n4 = new treeNode<int>(5);
    treeNode<int> * n5 = new treeNode<int>(6);

    root->children.push_back(n1);
    root->children.push_back(n2);
    root->children.push_back(n3);
    root->children.push_back(n4);
    root->children.push_back(n5);

    */

    treeNode<int> * root = takeInput();

    printTree(root);

    return 0;
}

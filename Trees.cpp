#include <iostream>
#include <bits/stdc++.h>
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

treeNode<int> * takeInputLevelWise()
{
    int rootData;
    cout<<"Enter rootData: ";
    cin>>rootData;
    treeNode<int> * root = new treeNode<int>(rootData);

    queue<treeNode<int>*> q;
    q.push(root);

    while(!q.empty())
    {
        treeNode<int> * f = q.front();
        q.pop();

        cout<<"Enter number of children of "<<f->data<<": "<<endl;
        int n;
        cin>>n;

        for(int i =0; i<n; i++)
        {
            int childData;
            cout<<"Enter "<<i+1<<"th child of "<<f->data<<endl;
            cin>>childData;

            treeNode<int> * childNode = new treeNode<int>(childData);
            q.push(childNode);
            f->children.push_back(childNode);
        }
    }

    return root;
}

/*
treeNode<int> * takeInput2()
{
    int rootData;
    cout<<"Enter rootData: ";
    cin>>rootData;

    treeNode<int> * root = new treeNode<int>(rootData);

    queue<treeNode<int>*> q;
    q.push(root);

    while(!q.empty())
    {
        treeNode<int> * f = q.front();
        q.pop();

        int n;
        cout<<"Enter number of children of "<<f->data<<": ";
        cin>>n;

        for(int i =0; i<n; i++)
        {
            int child;
            cout<<"Enter "<<i+1<<"th child of "<<f->data<<": ";
            cin>>child;

            treeNode<int> * childNode = new treeNode<int>(child);
            q.push(childNode);
            f->children.push_back(childNode);
        }

    }

    return root;
}
*/

void printLevelWise(treeNode<int> * root)
{
    queue<treeNode<int>*> q;
    q.push(root);

    while(!q.empty())
    {
        treeNode<int> * f = q.front();
        q.pop();

        cout<<f->data<<": ";

        for(int i=0; i<f->children.size(); i++)
        {
            cout<<f->children[i]->data<<" ";
        }
        cout<<endl;

        for(int i =0; i<f->children.size(); i++)
        {
            q.push(f->children[i]);
        }
    }
}

///Count Nodes iteration method
int countNodes(treeNode<int>* root)
{
    if(!root){
        cout<<"Tree doesn't exist"<<endl;
        return 0;
    }
    int count = 1;
    queue<treeNode<int>*> q;
    q.push(root);

    while(!q.empty())
    {
        treeNode<int> * f = q.front();
        q.pop();

        for(int i = 0; i<f->children.size(); i++)
        {
            count++;
            q.push(f->children[i]);
        }
    }
    return count;
}

///Count Nodes - Recursion method
int countNodesRec(treeNode<int> * root)
{
    if(!root)
    {
        cout<<"Tree does not exist"<<endl;
        return 0;
    }
    int count = 1;

    for(int i = 0; i<root->children.size(); i++)
    {
        count += countNodesRec(root->children[i]);
    }
    return count;
}

///Height of tree - Recursive
int heightOfTree(treeNode<int> * root)
{
    if(!root)
    {
        cout<<"Tree does not exist"<<endl;
        return 0;
    }
    int maxHeight = 0;

    for(int i = 0; i<root->children.size(); i++)
    {
        int height = heightOfTree(root->children[i]);
        if(height > maxHeight)
        {
            maxHeight = height;
        }
    }
    return maxHeight + 1;
}

///Print all nodes at level K
void printNodesAtLevel(treeNode<int> * root, int level)
{
    if(!root)
    {
        cout<<"Tree does not exist"<<endl;
        return;
    }

    if(level == 0)
    {
        cout<<root->data<<" ";
        return;
    }

    for(int i = 0; i<root->children.size(); i++)
    {
        printNodesAtLevel(root->children[i], level-1);
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

    /*treeNode<int> * root = takeInput();*/
    /*treeNode<int> * root = takeInputLevelWise();*/
    treeNode<int> * root = takeInputLevelWise();

    printTree(root);
    cout<<endl;
    printLevelWise(root);
    cout<<endl;
    cout<<"Nodes in tree: "<<countNodes(root)<<endl;
    cout<<"Height of tree: "<<heightOfTree(root)<<endl;
    cout<<"Nodes at level 1: "<<endl;
    printNodesAtLevel(root, 1);

    return 0;
}

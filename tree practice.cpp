#include<bits/stdc++.h>
using namespace std;

template <typename T>
class treeNode
{
public:
    T data;
    vector<treeNode*> children;
    // vector<treeNode<T>*> children;  both of them are same.

    treeNode(T data)
    {
        this->data = data;
    }
};

treeNode<int>* takeInputLevelWise()
{
    int rootData;
    cout<<"Enter root data: ";
    cin>>rootData;

    treeNode<int>* root = new treeNode<int>(rootData);
    queue<treeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0)
    {
        treeNode<int>* frontt = pendingNodes.front();
        pendingNodes.pop();

        int numChild;
        cout<<"Enter total number of child of "<<frontt->data<<" : ";
        cin>>numChild;

        for(int i=0; i<numChild; i++)
        {
            int data;
            cout<<"Enter "<<i<<"th child of "<<frontt->data<<" : ";
            cin>>data;

            treeNode<int>* child = new treeNode<int>(data);
            frontt->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

void printTreeLevelWise(treeNode<int>* root)
{
    // edge case
    if(root == NULL) return;

    queue<treeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0)
    {
        treeNode<int>* frontt = pendingNodes.front();
        pendingNodes.pop();

        cout<<frontt->data<<" :    ";
        for(int i=0; i<frontt->children.size(); i++)
        {
            treeNode<int>* child = frontt->children[i];
            cout<<child->data<<",  ";
            pendingNodes.push(child);
        }
        cout<<"\n\n";
    }
}

int main()
{
    treeNode<int>* root = takeInputLevelWise();
    printTreeLevelWise(root);
}

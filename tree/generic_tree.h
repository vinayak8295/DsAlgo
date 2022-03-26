#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class TreeNode{
public:
	int data ;
	vector<TreeNode*> children;
	TreeNode(int data){
		this->data = data;
	}

    TreeNode* takeInputLevelWise(){
    int data;
    cout<<"Enter Root Data"<<endl;
    cin>>data;
    TreeNode* root = new TreeNode(data);
    queue<TreeNode*> pending_nodes;
    pending_nodes.push(root);
    while (pending_nodes.size()!=0)
    {
        auto front = pending_nodes.front();
        pending_nodes.pop();
        cout<<"Enter no. of children of "<<front->data<<endl;
        int child;
        cin>>child;
        for (int i = 0; i < child; i++)
        {
            int childData;
      	    cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            cin>>childData;
      	    TreeNode* child = new TreeNode(childData);
      	    front->children.push_back(child);
      	    pending_nodes.push(child);

        }
    }
    return root;
}
};

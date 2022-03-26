#include<iostream>
#include "generic_tree.h"
#include<bits/stdc++.h>

using namespace std;



void Level_order(TreeNode* root){
    if(root==NULL){
       cout<<-1<<endl;
    }
    queue<TreeNode*> pending_nodes;
    pending_nodes.push(root);
    while (pending_nodes.size()!=0)
    {
        auto front = pending_nodes.front();
        pending_nodes.pop();
        cout<<front->data<<" ";
        for (int i = 0; i < front->children.size(); i++)
        {
             pending_nodes.push(front->children[i]);
        }
        cout<<endl;
        
    }
    
}
int main(){
    TreeNode* root;
    root = root->takeInputLevelWise();
    Level_order(root);
   return 0;

}
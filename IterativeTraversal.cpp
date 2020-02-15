
#include<bits/stdc++.h>
using namespace std;


struct node{
    int val;
    node* left,*right;
    node(int x){
        val=x;
        left=right=NULL;
    }
};


unordered_map<node*,int> cnt;


void preorder(node* root){
    stack<node*> s;
    
    s.push(root);
    while(!s.empty()){
        node* cur=s.top();
        if(cur==NULL){
            s.pop();
            continue;
        }
        if(cnt[cur]==0)cout<<cur->val<<" ";
        else if(cnt[cur]==1)s.push(cur->left);
        else if(cnt[cur]==2)s.push(cur->right);
        else s.pop();
        cnt[cur]++;
    }
}


int main(){
    
    node *root=new node(7);
    root->left=new node(3);
    root->left->left=new node(2);
    root->left->right=new node(5);
    root->left->left->left=new node(1);
    
    root->right=new node(10);
    root->right->left=new node(8);
    root->right->right=new node(12);
    
    inorder(root);
    
}

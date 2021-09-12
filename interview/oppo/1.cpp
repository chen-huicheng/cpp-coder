#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left,*right;
};

bool isBeautyTree(TreeNode *root){
    queue<TreeNode*> que;
    que.push(root);
    TreeNode *end=root;
    int lev=0,pre=-1;
    while(!que.empty()){
        auto p=que.front();
        que.pop();
        if(p->val<=pre||p->val%2!=lev%2){
            return false;
        }
        pre=p->val;
        if(p->left!=nullptr){
            que.push(p->left);
        }
        if(p->right!=nullptr){
            que.push(p->right);
        }
        if(p==end){
            end=que.back();
            pre=-1;
            lev++;
        }
    }
    return true;
}
int main(){
    
    return 0;
}
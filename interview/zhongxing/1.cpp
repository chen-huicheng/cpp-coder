#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left,*right;
    TreeNode(int k):val(k),left(nullptr),right(nullptr){}
};
struct ListNode{
    int val;
    ListNode *next;
};
void build(TreeNode *head,ListNode *list){
    if(list==nullptr)return;
    if(head->left==nullptr){
        head->left=new TreeNode(list->val);
        build(head->left,list->next);
    }
    else if(head->left->val==list->val){
        build(head->left,list->next);
    }
    else if(head->right==nullptr){
        head->right=new TreeNode(list->val);
        build(head->right,list->next);
    }
    else{
        build(head->right,list->next);
    }
}
TreeNode *recoverTree(vector<ListNode*> &list){
    if(list.size()==0)return nullptr;
    TreeNode *head=new TreeNode(list[0]->val);
    for(auto l:list){
        build(head,l->next);
    }
    return head;
}
int main(){
    
    return 0;
}
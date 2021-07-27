#include <iostream>
#include<queue>
#include<list>
#include<map>
//树的层次遍历
using namespace std;
class Node{
public:
    Node(int n):val(n),right(NULL),left(NULL){}
    int val;
    Node *right,*left;
};
void bfs(Node *root){
    int lineno=0;
    queue<Node*> que;
    que.push(root);
    int num=1,curnum=0;
    Node *p;
    while(!que.empty()){
        p=que.front();
        que.pop();
        num--;
        cout<<lineno<<" "<<p->val<<endl;
        if(p->left!=NULL){
            curnum++;
            que.push(p->left);
        }
        if(p->right!=NULL){
            curnum++;
            que.push(p->right);
        }
        if(num==0){
            lineno++;
            num=curnum;
            curnum=0;
        }
    }
}

//判断是否有环
bool check(map<int,list<int>> &m,vector<int> &vis,int cur){
    for(auto i:m[cur]){
        if(vis[i]==0){
            vis[i]=1;
            check(m,vis,i);
            vis[i]=0;
        }
        else{
            return true;
        }
    }
    return false;
}
bool hascircle(map<int,list<int>> &m,int n){
    for(int i=0;i<n;i++){
        int cur=i;
        vector<int>vis(n,0);
        vis[cur]=1;
        if(check(m,vis,cur)){
            return true;
        }
    }
    return false;
}
int main() {
    Node *root;
    root = new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    bfs(root);
//     cout << "Hello World!" << endl;
}
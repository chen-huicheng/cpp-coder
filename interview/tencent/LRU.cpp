#include<bits/stdc++.h>
using namespace std;
struct Node{
    int key,val;
    Node *pre,*next;
    Node():key(0),val(0),pre(nullptr),next(nullptr){}
    Node(int k,int v):key(k),val(v),pre(nullptr),next(nullptr){}
};
class LRU{
    public:
    LRU(size_t cap):capacity(cap){
        head.pre=&head;
        head.next=&head;
    }
    int set(int key,int val){
        if(m.find(key)!=m.end()){
            m[key]->val=val;
            moveToTop(m[key]);
        }else{
            m[key]=new Node(key,val);
            insertToTop(m[key]);
            if(m.size()>=capacity){
                move();
            }
        }
    }
    int get(int key){
        if(m.count(key)){
            moveToTop(m[key]);
            return m[key]->val;
        }
        return -1;
    }
    void move(){
        Node *p = m[head.pre->val];
        p->next->pre=p->pre;
        p->pre->next=p->next;
        m.erase(p->key);
        delete p;
    }
    void moveToTop(Node *p){
        p->next->pre=p->pre;
        p->pre->next=p->next;
        insertToTop(p);
    }
    void insertToTop(Node *p){
        p->next=head.next;
        head.next->pre=p;
        p->pre=&head;
    }
    private:
    size_t capacity;
    Node head;
    map<int,Node*> m;
};
int main(){
    
    return 0;
}
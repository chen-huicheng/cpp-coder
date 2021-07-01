// struct node {
//     struct node *left;
//     struct node *right;
//     int value;
// };

// int pre=-1;
// bool isBST(node* root) {
//     if(root==nullptr)return true;
//     if(!isBST(root->left)){
//         return false;
//     }
//     if(pre!=-1&&pre>root->value){
//         return false;
//     }
//     pre=root->value;
//     if(!isBST(root->right)){
//         return false;
//     }
//     return true;
// }

// char * const p;
// char const * p;
// const char *p;
// #include <stdio.h>
// struct
// {
//     int x;
//     char y;
// } s;

// int main()
// {
//     printf("%d\n", sizeof(s));//8
//     return 0;
// }

/*
 * shared_ptr
 */
#include <memory>
#include <unistd.h>
using namespace std;

class A
{
public:
    void work() { me = shared_ptr<A>(this); }
    // private:
    shared_ptr<A> me;
};

int main()
{
    {
        A *t = new A;
        shared_ptr<A> p(t);
        p->work();

        int k = p.use_count();   //1
        int d = p->me.use_count();//1
        k=3;
    }
    sleep(3);
    return 0;
}
/*
 * shared_ptr
 */
// int main(){
//     int* pi = (int*)malloc(4 * sizeof(int));
//     {
//         shared_ptr<int> sp(pi);
//     }
//     return 0;
// }

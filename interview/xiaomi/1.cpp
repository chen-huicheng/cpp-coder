#include<bits/stdc++.h>
using namespace std;
int main(){
    char c[]={1,2,3,4,5,6};
    void *p =c;
    printf("%p\n",*static_cast<int*>(p));
    p=p+1;
    printf("%p\n",*static_cast<int*>(p));
}
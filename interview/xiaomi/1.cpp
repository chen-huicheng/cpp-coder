#include<bits/stdc++.h>
using namespace std;
int *f0(){
    return 0;
}
int (*k)[10];
typedef declare(k) pa;
int f1(){
    return 0;
}
int f2(){
    return 0;
}
int main(){
    int *(*fp1)(); //fp1是一个函数指针 返回值int*
    fp1 = &f0;

    int (*(*fp2)())[10]; //fp2是一个函数指针 
    int (*k)[10]=fp2(); //函数的返回值类型
    (*k)[0]=1;
    *k[1]=2;

    int (*(*fp3[10])()); //fp3是一个数组 数组元素是函数指针
    fp3[0] = &f0;

    // char c[]={1,2,3,4,5,6};
    // void *p =c;
    // printf("%p\n",*static_cast<int*>(p));
    // p=p+1;
    // printf("%p\n",*static_cast<int*>(p));
}
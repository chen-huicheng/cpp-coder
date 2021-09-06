#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[5];
    int *p=a;
    *p=35;
    *(p+1)=56;
    printf("%d",(*p++));
}
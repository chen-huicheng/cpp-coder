#include<bits/stdc++.h>
using namespace std;
int main(){
    #if  __WORDSIZE ==  64
        printf("64\n");
    #else
        printf("32\n");
    #endif
    return 0;
}
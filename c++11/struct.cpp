#include<bits/stdc++.h>
using namespace std;
struct Data{
    int i;
};

unsigned char data[16]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
int main(){
    Data d;
    memccpy(&d,data,sizeof(d),sizeof(d));
    cout<<d.i<<endl;
    printf("0x%x\n",d.i);
    return 0;
}
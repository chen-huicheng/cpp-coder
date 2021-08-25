#include<bits/stdc++.h>
using namespace std;
int main(){
    double d,mind;
    cin>>d;
    mind=d;
    int n,m;
    for(int i=1;i<=200;i++){
        for(int j=0;j<=i;j++){
            if(fabs((1.0*j)/i-d)<mind){
                mind = fabs((1.0*j)/i-d);
                n=i;
                m=j;    
            }
        }
    }
    cout<<"["<<m<<","<<n<<"]"<<endl;
    return 0;
}
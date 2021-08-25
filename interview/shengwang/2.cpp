#include<bits/stdc++.h>
using namespace std;

vector<int> func(vector<int> &input){
    int n=input.size();
    vector<int> result(n),left(n,1),right(n,1);
    for(int i=0;i<n-1;i++){
        left[i+1]=left[i]*input[i];
        right[n-i-2]=right[n-i-1]*input[n-i-1];
    }
    for(int i=0;i<n;i++){
        result[i]=left[i]*right[i];
    }
    return result;
}
int main(){
    vector<int> input={2,3,4,5};
    input = func(input);
    for(auto in:input){
        cout<<in<<endl;
    }   
    return 0;
}

int getH(vector<int> &bag,int s){
    int res=0;
    for(auto b:bag){
        res+=(b+s-1)/s;
    }
    return res;
}
int minS(vector<int> &bag,int H){
    int n=bag.size();
    if(H<n)return -1;//怎么也吃不完
    int left=INT_MAX,right=INT_MIN;
    for(auto b:bag){
        left=min(left,b);
        right=max(right,b);
    }
    while(left<right){
        int mid=(left+right)/2;
        int tmph=getH(bag,mid);
        if(tmph>H){
            left=mid+1;
        }else{
            left=mid;
        }
    }
    return left;
}

int times(int n){//初始位置为 0 台阶
    if(n<2)return 1;
    int pre1=1,pre2=1,cur;
    for(int i=2;i<=n;i++){
        cur=pre1+pre2;
        pre1=pre2;
        pre2=cur;
    }
    return cur;
}


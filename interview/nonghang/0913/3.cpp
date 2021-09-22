#include<bits/stdc++.h>
using namespace std;
int measure(int x, int y)
{	
	int z = y;
	while(x%y!=0)
	{
		z = x%y;
		x = y;
		y = z;	
	}
	return z;
}
const int INT_MAX=1e9;
int split(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n+1,INT_MAX);
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(dp[j]==INT_MAX)continue;
            if(measure(nums[i],nums[j])!=1){
                dp[i+1]=min(dp[i+1],dp[j]+1);
            }
        }
    }
    return dp[n];
}
int main(){
    vector<int>nums{4,5,51};
    cout<<split(nums)<<endl;    
    return 0;
}
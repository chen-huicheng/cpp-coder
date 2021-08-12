#include<bits/stdc++.h>
using namespace std;

vector<int> getNext(string str)
{
    int n= str.size();
	vector<int> next(n,0);
    next[0]=-1;
	int i = 0, j = -1;

	while (i < n)
	{
		if (j == -1 || str[i] == str[j])
		{
			++i;
			++j;
			next[i] = j;
		}	
		else
			j = next[j];
	}
    return next;
}
int Kmp(string str,string sub){
    vector<int> next = getNext(sub);
    int i=0,j=0;
    int n=str.size(),m=sub.size();
    while(i<n&&j<m){
        if(j==-1||str[i]==sub[j]){
            i++;
            j++;
        }else{
            j=next[j];
        }
    }
    if(j==m){
        return i-j;
    }else{
        return -1;
    }
}
int main(){
    string str,sub;
    cin>>str>>sub;
    int idx=Kmp(str,sub);
    // cout<<idx<<endl;
    return 0;
}
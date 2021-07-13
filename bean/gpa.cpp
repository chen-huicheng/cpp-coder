#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> score = {0, 60, 62, 65, 67, 70, 75, 80, 85, 90, 95};
vector<float> gpa = {0, 1.0, 1.7, 2.0, 2.3, 2.7, 3.0, 3.3, 3.7, 4.0, 4.3};
float f(int n)
{
    if (n < 60)
    {
        // cout << 0 << endl;
        return 0;
    }
    float res = 0;
    for (int i = 0; i < 11; i++)
    {
        for (int j = i; j < 11; j++)
        {
            for (int x = j; x < 11; x++)
            {
                if (score[i] + score[j] + score[x] <= n)
                {
                    int idx = lower_bound(score.begin(), score.end(), n - (score[i] + score[j] + score[x])) - score.begin();
                    // cout<<n - (score[i] + score[j] + score[x])<<" "<<idx<<endl;
                    if(idx==11||score[idx]>n - (score[i] + score[j] + score[x]))
                        idx = max(idx - 1, 0);
                    res = max(res, gpa[i] + gpa[j] + gpa[x] + gpa[idx]);
                }
            }
        }
    }
    return res;
}
double maxnum;
const int N=11;
int low_g[N]={95,90,85,80,75,70,67,65,62,60,0};//每档次绩点对应最低分
double scores[N]={4.3,4.0,3.7,3.3,3.0,2.7,2.3,2.0,1.7,1.0,0};//绩点 
double score_to_grade(double score)//根据分数得出相应绩点 
{
	if(score>=95)
		return scores[0];
	else if(score>=90)
		return scores[1];
	else if(score>=85)
		return scores[2];
	else if(score>=80)
		return scores[3];
	else if(score>=75)
		return scores[4];
	else if(score>=70)
		return scores[5];
	else if(score>=67)
		return scores[6];
	else if(score>=65)
		return scores[7];
	else if(score>=62)
		return scores[8];
	else if(score>=60)
		return scores[9];
	else
		return scores[10];
}
void dfs(int i,int sum,double score)//深度搜索 
{
	if(sum<0)
		return;
	if(i==3)//最多4门课
	{
		maxnum=max(maxnum,score_to_grade(sum)+score);//取最大绩点和 
		return ;
	}
	for(int j=0;j<N;j++)//循环，枚举每门课的分数档次能够获得的绩点 
		dfs(i+1,sum-low_g[j],score+scores[j]);//深度搜优先索
}
// int main()
// {
// 	int r,total;
// 	cin>>r;
// 	while(r--)
// 	{
// 		cin>>total;
// 		maxnum=0;
// 		dfs(0,total,0);
// 		cout<<setiosflags(ios::fixed)<<setprecision(1);//保留一位小数 
// 		cout<<maxnum<<'\n';
// 	}
// 	return 0;
// }

int main()
{
    for(int i=0;i<400;i++){
        maxnum=0;
		dfs(0,i,0);
        if(maxnum-f(i)>0.001)
            cout<<maxnum<<" "<<f(i)<<endl;

    }
    return 0;
}

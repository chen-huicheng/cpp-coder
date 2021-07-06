#include <queue>
#include <random>
#include <iostream>
#include<fstream>
using namespace std;
int main()
{
    int k = 10;
    priority_queue<int> que;
    for (int i = 0; i < k; i++)
    {
        que.push(rand() % k);
    }
    while (!que.empty())
    {
        int top = que.top();
        cout << top << " ";
        que.pop();
    }
    ofstream fout("file.txt");
    string buf;
    while(cin>>buf){
        if(buf=="exit")break;
        fout<<buf<<endl;
    }
}
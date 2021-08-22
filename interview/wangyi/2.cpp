#include<bits/stdc++.h>
#define maxn 1505
#define inf 1<<29
using namespace std;

int e[maxn][maxn],dis[maxn][maxn];

void init(int n) {
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == j)
                e[i][j] = dis[i][j] = 0;
            else
                e[i][j] = dis[i][j] = inf;
        }
    }
}

int Floyd(int n) {
    int mincircle = inf;
    for(int k = 0; k <= n; k++) {
        for(int i = 0; i < k; i++) {
            for(int j = i+1; j < k; j++) {
                mincircle = min(mincircle,e[i][k]+e[k][j]+dis[i][j]);   //最小环公式;
            }
        }
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]); //正常Floyd;
            }
        }
    }
    return mincircle;
}

int main() {
    int n,m,u,v,w,ans;
    while(cin>>n>>m) {
        init(n);
        for(int i = 0; i < m; i++) {
            cin>>u>>v>>w;
            e[u][v] = dis[u][v] = w;
            e[v][u] = dis[v][u] = w;
        }
        ans = Floyd(n);
        if(ans == inf)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}

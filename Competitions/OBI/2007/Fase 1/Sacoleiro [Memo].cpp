#include <bits/stdc++.h>

const int MAXC = 35;
const int MAXM = 110;

using namespace std;

int memo[MAXC][MAXM][MAXM], t, price[MAXC];
char type[MAXC];
vector <int> adj[MAXC];

int dp(int u, int boy, int girl){
    int &ret = memo[u][boy][girl];

    if(ret < MAXM) return ret;

    if(boy or girl) ret = abs(boy - girl);

    if(boy + girl + price[u] <= t){
        if(type[u] == 'A'){
            ret = min(ret, dp(u, boy + price[u], girl));
        }else{
            ret = min(ret, dp(u, boy, girl + price[u]));
        }
    }

    for(int i = 0; i < (int)adj[u].size(); i++){
        int v = adj[u][i];
        ret = min(ret, dp(v, boy, girl));
    }

    return ret;
}

int main(){
    int n, k, v;

    scanf("%d %d", &n, &t);

    for(int i = 0; i < n; i++){
        scanf("%*d %d %c %d", &price[i], &type[i], &k);

        while(k--){
            scanf("%d", &v);
            adj[i].push_back(v);
        }
    }

    //Memset troll
    for(int i = 0; i < MAXC; i++){
        for(int j = 0; j < MAXM; j++){
            for(int k = 0; k < MAXM; k++){
                memo[i][j][k] = MAXM;
            }
        }
    }

    printf("%d\n", dp(0, 0, 0));

    return 0;
}


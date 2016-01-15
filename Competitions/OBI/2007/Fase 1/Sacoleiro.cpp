/*Brute Force*/

#include <bits/stdc++.h>

const int MAXC = 35; //Max City
const int MAX = 110; //Max Money

using namespace std;

bool can[MAXC][MAX][MAX];
int t, price[MAXC];
char type[MAXC];
vector <int> adj[MAXC];

void pre_process(int u, int boy, int girl){
    if(boy + girl > t) return;

    if(can[u][boy][girl]) return;

    can[u][boy][girl] = true;

    if(type[u] == 'A')
        pre_process(u, boy + price[u], girl);
    else
        pre_process(u, boy, girl + price[u]);

    for(int i = 0; i < (int)adj[u].size(); i++){
        int v = adj[u][i];
        pre_process(v, boy, girl);
    }
}

int main(){
    int n, k, v, ans = INT_MAX;

    scanf("%d %d", &n, &t);

    for(int i = 0; i < n; i++){
        scanf("%*d %d %c %d", &price[i], &type[i], &k);
        while(k--){
            scanf("%d", &v);
            adj[i].push_back(v);
        }
    }

    pre_process(0, 0, 0);

    for(int u = 0; u < n; u++){
        for(int boy = 0; boy <= t; boy++){
            for(int girl = 0; girl <= t; girl++){
                if((boy || girl) && can[u][boy][girl]){
                    ans = min(ans, abs(boy - girl));
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}

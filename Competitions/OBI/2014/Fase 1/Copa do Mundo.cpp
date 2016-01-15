/*Grafos, MST, Kruskal's Algorithm*/

#include <bits/stdc++.h>

const int MAXV = 110;
const int MAXE = 5010;

using namespace std;

typedef pair <int, pair<int, int> > iii;

iii edges[MAXE];
int id[MAXV], rk[MAXV];

int find_set(int x){
    if(id[x] == x) return x;
    return id[x] = find_set(id[x]);
}

bool union_set(int x, int y){
    x = find_set(x); y = find_set(y);

    if(x != y){
        if(rk[x] > rk[y]){
            id[y] = x;
            rk[x] += rk[y];
        }else{
            id[x] = y;
            rk[y] += rk[x];
        }
        return true;
    }
    return false;
}

int main(){

    int n, f, r, x, y, c;

    scanf("%d %d %d", &n, &f, &r);

    for(int i = 0; i < n; i++){
        id[i] = i; rk[i] = 0;
    }

    for(int i = 0; i < f; i++){
        scanf("%d %d %d", &x, &y, &c);
        edges[i] = make_pair(c, make_pair(x - 1, y - 1));
    }

    int endd = f + r;

    for(int i = f; i < endd; i++){
        scanf("%d %d %d", &x, &y, &c);
        edges[i] = make_pair(c, make_pair(x - 1, y - 1));
    }

    sort(edges, edges + f);
    sort(edges + f, edges + endd);

    int ans = 0, cont = 0;

    for(int i = 0; i < endd && cont < n - 1; i++){
        c = edges[i].first;
        x = edges[i].second.first; y = edges[i].second.second;

        if(union_set(x, y)){
            cont++;
            ans += c;
        }
    }

    printf("%d\n", ans);

    return 0;
}

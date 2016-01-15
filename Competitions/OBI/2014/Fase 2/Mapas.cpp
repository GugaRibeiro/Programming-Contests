/*Union-Find, Matemática, Grafos*/

#include <bits/stdc++.h>

const int MAXV = 100010;

using namespace std;

typedef long long ll;

int id[MAXV];
ll rk[MAXV];

int find_set(int x){
    if(id[x] == x) return x;
    return id[x] = find_set(id[x]);
}

void union_set(int x, int y){
    x = find_set(x), y = find_set(y);
    if(x != y){
        id[y] = x;
        rk[x] += rk[y];
    }
}

int main(){

    int x, y, flag;
    ll ans, n;

    cin >> n;

    ans = n * (n - 1) / 2;

    for(int i = 1; i <= n; i++){
        id[i] = i; rk[i] = 1;
    }

    for(int i = 1; i < n; i++){
        scanf("%d %d %d", &x, &y, &flag);

        if(!flag){
            union_set(x, y);
        }
    }

    for(int i = 1; i <= n; i++){
        if(id[i] == i){
            ans -= rk[i] * (rk[i] - 1) / 2;
        }
    }

    cout << ans << "\n";

    return 0;
}

/*Árvores, implementação
**checagem de árvore balanceada
**O(V + E)*/

#include <bits/stdc++.h>

const int MAXV = 10010;

using namespace std;

vector <int> adj[MAXV];

int dfs(int u){
    int total = 0, aux, quant;

    for(int i = 0; i < (int)adj[u].size(); i++){
        int v = adj[u][i];

        aux = dfs(v);

        if(!i) quant = aux;
        if(aux != quant || aux == -1) return -1;

        total += aux;
    }
    return total + 1;
}

int main(){
    int n, u, v;

    cin >> n;
    while(n--){
        cin >> u >> v;
        adj[v].push_back(u);
    }

    puts(dfs(0) == -1 ? "mal" : "bem");

    return 0;
}

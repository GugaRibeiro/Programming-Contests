/*Grafos, Depth-First Search
**Busca, checagem de grafo conexo, Propriedades dos Grafos Eulerianos
**O(V + E)*/

#include <bits/stdc++.h>

using namespace std;

bool mat[10][10], mark[10];
int grau[10];

void dfs(int vtx){
    mark[vtx] = true;

    for(int i = 0; i < 7; i++)
        if(mat[vtx][i] and !mark[i])
            dfs(i);
}

bool isConnected(){
    int i;

    for(i = 0; !grau[i]; i++);

    dfs(i);

    for(int i = 0; i < 7; i++){
        if(grau[i] and !mark[i]){
            return false;
        }
    }
    return true;
}

int main(){

    int n, x, y, imp, test = 1;

    while(scanf("%d", &n), n){
        for(int i = 0; i < 7; i++){
            for(int j = 0; j < 7; j++){
                mat[i][j] = false;
            }
            mark[i] = false;
            grau[i] = 0;
        }

        while(n--){
            scanf("%d %d", &x, &y);
            grau[x]++;
            grau[y]++;
            mat[x][y] = mat[y][x] = true;
        }

        imp = 0;

        for(int i = 0; i < 7; i++){
            if(grau[i] % 2 == 1)
                imp++;
        }

        printf("Teste %d\n", test++);

        if((imp != 0 and imp != 2) or !isConnected())
            puts("nao\n");
        else
            puts("sim\n");
    }

    return 0;
}

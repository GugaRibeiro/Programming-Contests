/*Grafos: All Pairs Shortst Paths, Diâmetro do grafo
**Floyd-Warshall's Algorithm
**O(v³)*/

#include <bits/stdc++.h>

const int MAXV = 110;
const int INF = 10000;

using namespace std;

int mat[MAXV][MAXV];

void floyd_warshall(int v){
    for(int k = 1; k <= v; k++)
        for(int i = 1; i <= v; i++)
            for(int j = 1; j <= v; j++)
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
}

int main(){

    int v, test = 1, x, y, ans, _max, _min;

    while(scanf("%d", &v), v){

        for(int i = 1; i <= v; i++){
            for(int j = 1; j <= v; j++)
                mat[i][j] = INF;
            mat[i][i] = 0;
        }

        for(int i = 0; i < v - 1; i++){
            scanf("%d %d", &x, &y);
            mat[x][y] = mat[y][x] = 1;
        }

        floyd_warshall(v);

        _min = INF;
        ans = -1;

        for(int i = 1; i <= v; i++){
            _max = -1;
            for(int j = 1; j <= v; j++){
                if(mat[i][j] < INF and _max < mat[i][j])
                    _max = mat[i][j];
            }
            if(_max < _min){
                _min = _max;
                ans = i;
            }
        }

        printf("Teste %d\n%d\n\n", test++, ans);
    }

    return 0;
}

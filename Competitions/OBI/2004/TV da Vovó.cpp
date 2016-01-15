/*Matrizes
**O(n²)*/

/*Seja HOR o somatório dos deslocamentos horizontais e VER o inverso do somatório dos deslocamentos verticais,
**temos que um ponto qualquer (x, y) da matriz após os deslocamentos será definido como:
** x = (N + (i - HOR) % N) % N e y = (M + (j - VER) % M) % M, onde N e M representam quantidade de linhas e colunas da matriz
**respectivamente, i e j representam a posição atual da matriz*/

#include <bits/stdc++.h>

using namespace std;

int calc(int i, int d, int tam){
    return (tam + (i - d) % tam) % tam;
}

int main(){

    int n, m, mat[1010][1010], hor, ver, test = 1, x, y;

    while(scanf("%d %d", &n, &m), n){

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                scanf("%d", &mat[i][j]);
            }
        }

        hor = ver = 0;

        while(scanf("%d %d", &x, &y), x or y){
            hor += x;
            ver += y;
        }
        ver = -ver;

        printf("Teste %d\n", test++);

        for(int i = 0; i < n; i++){
            x = calc(i, ver, n);
            y = calc(0, hor, m);

            printf("%d", mat[x][y]);
            for(int j = 1; j < m; j++){
                x = calc(i, ver, n);
                y = calc(j, hor, m);

                printf(" %d", mat[x][y]);
            }
            putchar('\n');
        }

        putchar('\n');
    }

    return 0;
}

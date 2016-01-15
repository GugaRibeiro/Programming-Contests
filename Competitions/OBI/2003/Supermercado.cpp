/*Algoritmo Guloso / Ordenação / Matemática : Medianas
**O(n log n)*/

#include <bits/stdc++.h>

using namespace std;

int cmp(int a, int b){
    return a - b;
}

int main(){

    int n, X[1010], Y[1010], test = 1;

    while(scanf("%d", &n), n){

        for(int i = 0; i < n; i++)
            scanf("%d %d", &X[i], &Y[i]);

        sort(X, X + n);
        sort(Y, Y + n);

        printf("Teste %d\n%d %d\n\n", test++, X[n / 2], Y[n / 2]);
    }

    return 0;
}

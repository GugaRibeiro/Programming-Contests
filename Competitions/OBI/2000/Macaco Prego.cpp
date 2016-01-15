/*Geometria / Algoritmo Guloso
**O(n)*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, x, y, u, v, a, b, c, d, test = 1;

    while(scanf("%d", &n), n){

        x = v = -10000;
        y = u = 10000;

        while(n--){
            scanf("%d %d %d %d", &a, &b, &c, &d);

            x = max(x, a);
            y = min(y, b);
            u = min(u, c);
            v = max(v, d);
        }

        printf("Teste %d\n", test++);

        if(x > u or v > y)
            puts("nenhum\n");
        else
            printf("%d %d %d %d\n\n", x, y, u, v);
    }

    return 0;
}

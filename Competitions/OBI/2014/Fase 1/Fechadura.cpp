/*Algoritmo Guloso, implementação*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, m, fechadura[1010], ans = 0, aux;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        scanf("%d", &fechadura[i]);

    for(int i = 0; i < n; i++){
        if(fechadura[i] > m){
            aux = fechadura[i] - m;
            fechadura[i + 1] -= aux;
            ans += aux;
        }else{
            aux = m - fechadura[i];
            fechadura[i + 1] += aux;
            ans += aux;
        }
    }

    printf("%d\n", ans);

    return 0;
}

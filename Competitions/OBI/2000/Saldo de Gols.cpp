/*Programação Dinâmica: Maximum Subarray Problem
**Adaptação do Algoritmo de Kadane
**O(n)*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, test = 1, a, b, saldo, aux, ini, fim, _max;

    while(scanf("%d", &n), n){
        saldo = 0;
        aux = 1;
        _max = -1;
        for(int i = 1; i <= n; i++){
            scanf("%d %d", &a, &b);

            saldo += a - b;

            if(saldo < 0){
                saldo = 0;
                aux = i + 1;
            }else if((saldo and saldo > _max) or
                     (saldo == _max and i - aux > fim - ini)){
                ini = aux;
                fim = i;
                _max = saldo;
            }
        }

        printf("Teste %d\n", test++);

        if(_max == -1)
            puts("nenhum\n");
        else
            printf("%d %d\n\n", ini, fim);
    }

    return 0;
}

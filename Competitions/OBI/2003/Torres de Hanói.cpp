/*Matemática / Relações de Recorrência
**O(1)*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, test = 1;

    while(scanf("%d", &n), n){
        printf("Teste %d\n%d\n\n", test++, (1 << n) - 1);
    }

    return 0;
}

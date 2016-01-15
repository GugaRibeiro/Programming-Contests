/*Implementação
**O(n)*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, tc = 1, ans, aux;

    while(scanf("%d", &n), n){

        for(int i = 1; i <= n; i++){
            scanf("%d", &aux);
            if(aux == i)
                ans = aux;
        }

        printf("Teste %d\n%d\n\n", tc++, ans);
    }

    return 0;
}

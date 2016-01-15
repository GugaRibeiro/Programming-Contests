/*Implementação*/

#include <bits/stdc++.h>

using namespace std;

int n, vet[110];

int main(){

    int nota, ans = 0;

    scanf("%d", &n);

    while(n--){
        scanf("%d", &nota);
        vet[nota]++;
    }

    for(int i = 0; i <= 100; i++){
        if(vet[i] >= vet[ans])
            ans = i;
    }

    printf("%d\n", ans);

    return 0;
}

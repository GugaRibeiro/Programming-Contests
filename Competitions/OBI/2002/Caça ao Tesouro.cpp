/*Programação Dinâmica: Coin Change
**Algoritmo Guloso
**O(n * Σ(i : n) vet(i))*/

#include <bits/stdc++.h>

using namespace std;

bool dp[10010];
int vet[110];

int main(){

    int x, y, n, sum, div, act, test = 1;
    bool ans;

    while(scanf("%d %d %d", &x, &y, &n), n){
        ans = true;
        sum = 0;

        for(int i = 0; i < n; i++){
            scanf("%d", &vet[i]);
            sum += vet[i];
        }

        if((sum + x + y) % 2 != 0){
            ans = false;
        }else{
            memset(dp, false, sizeof dp);

            dp[0] = true;
            act = 0;
            div = (sum + x + y) / 2 - x;

            for(int i = 0; i < n; i++){
                for(int j = act; j >= 0; j--){
                    if(dp[j]){
                        dp[j + vet[i]] = true;
                    }
                }
                act += vet[i];
            }

            ans = dp[div];
        }

        printf("Teste %d\n", test++);

        puts(ans ? "S\n" : "N\n");
    }

    return 0;
}

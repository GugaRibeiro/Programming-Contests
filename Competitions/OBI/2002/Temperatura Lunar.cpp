/*Implementação
**O(n) com auxílio de um vetor acumulativo, O(1) para cada consulta*/

#include <bits/stdc++.h>

using namespace std;

int acum[10010];

int main(){

    int n, m, val, _min, _max, aux, test = 1;

    while(scanf("%d %d", &n, &m), n){
        acum[0] = 0;

        for(int i = 1; i <= n; i++){
            scanf("%d", &val);
            acum[i] = acum[i - 1] + val;
        }

        _min = INT_MAX;
        _max = INT_MIN;

        for(int i = 1; i + m - 1 <= n; i++){
            aux = (acum[i + m - 1] - acum[i - 1]) / m;
            _min = min(_min, aux);
            _max = max(_max, aux);
        }

        printf("Teste %d\n%d %d\n\n", test++, _min, _max);
    }

    return 0;
}

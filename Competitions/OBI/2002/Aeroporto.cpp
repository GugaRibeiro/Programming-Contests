/*Ordenação / Implementação
**O(n * log n)*/

#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> ii;

bool cmp(ii a, ii b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

int main(){

    ii aero[110];
    int n, v, a, b, test = 1;

    while(scanf("%d %d", &n, &v), n){
        for(int i = 0; i < n; i++){
            aero[i].first = 0;
            aero[i].second = i + 1;
        }

        while(v--){
            scanf("%d %d", &a, &b);
            a--; b--;
            aero[a].first++;
            aero[b].first++;
        }

        sort(aero, aero + n, cmp);

        a = aero[0].first;

        printf("Teste %d\n%d", test++, aero[0].second);

        for(int i = 1; i < n and aero[i].first == a; i++){
            printf(" %d", aero[i].second);
        }

        puts("\n");
    }

    return 0;
}

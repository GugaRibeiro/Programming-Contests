/*Ordenação / Implementação
**O(n * log n)*/

#include <bits/stdc++.h>

using namespace std;

typedef pair <string, int> si;

bool cmp(si a, si b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

int main(){

    int n, _min, _max, pos, p, test = 1;
    si comp[1010];

    while(scanf("%d", &n), n){
        getchar();
        for(int i = 0; i < n; i++){
            cin >> comp[i].first;

            comp[i].second = 0;
            _min = 1001;
            _max = -1;

            for(int j = 0; j < 12; j++){
                scanf("%d", &p);
                comp[i].second += p;
                _min = min(_min, p);
                _max= max(_max, p);
            }

            comp[i].second -= (_min + _max);
        }

        sort(comp, comp + n, cmp);

        printf("Teste %d\n1 %d %s\n", test++, comp[0].second, comp[0].first.c_str());
        pos = 1;

        for(int i = 1; i < n; i++){
            if(comp[i].second == comp[i - 1].second){
                printf("%d", pos);
            }else{
                printf("%d", i + 1);
                pos = i + 1;
            }

            printf(" %d %s\n", comp[i].second, comp[i].first.c_str());
        }

        putchar('\n');
    }

    return 0;
}

/*Geometria / Distância entre dois pontos
**O(n)*/

#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> ii;

int main(){

    int n, test = 1, x, y, ans;
    double _max, _min, dist;
    ii furos[1010];

    while(scanf("%d", &n), n){

        for(int i = 0; i < n; i++)
            scanf("%d %d", &furos[i].first, &furos[i].second);

        _min = INT_MAX;

        for(int i = 0; i < n; i++){
            _max = 0;
            for(int j = 0; j < n; j++){

                x = furos[i].first - furos[j].first;
                y = furos[i].second - furos[j].second;

                dist = hypot(x, y) + 2.5;

                _max = max(_max, dist);
            }
            _min = min(_min, _max);
        }

        printf("Teste %d\n%d\n\n", test++, (int)ceil(2 * _min));
    }

    return 0;
}

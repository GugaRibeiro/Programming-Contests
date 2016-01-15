/*Geometria
**Ponto dentro de um retângulo
**O(n)*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    int rx1, ry1, rx2, ry2, x, y, ans, test = 1, n;

    while(scanf("%d %d %d %d", &rx1, &ry1, &rx2, &ry2), rx1 or ry1 or rx2 or ry2){
        scanf("%d", &n);
        ans = 0;
        while(n--){
            scanf("%d %d", &x, &y);

            if(x >= rx1 and x <= rx2 and
               y <= ry1 and y >= ry2)
                ans++;
        }

        printf("Teste %d\n%d\n", test++, ans);
    }

    return 0;
}

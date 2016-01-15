/*Implementação
**O(n)*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, x, y, test = 1, a, b;

    while(scanf("%d", &n), n){
        a = b = 0;
        printf("Teste %d\n", test++);
        while(n--){
            scanf("%d %d", &x, &y);
            a += x;
            b += y;
            printf("%d\n", a - b);
        }

        puts("\n");
    }

    return 0;
}

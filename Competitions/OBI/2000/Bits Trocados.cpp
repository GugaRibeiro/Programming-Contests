/*Algoritmo Guloso
**O(1)*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    int V, tc = 1;

    while(scanf("%d", &V), V){

        printf("Teste %d\n", tc++);

        printf("%d", V / 50);
        V %= 50;
        printf(" %d", V / 10);
        V %= 10;
        printf(" %d", V / 5);
        V %= 5;
        printf(" %d\n\n", V);
    }

    return 0;
}

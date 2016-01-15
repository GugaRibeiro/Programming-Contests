/*Implementação
**O(n)*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, ans, num, test = 1;
    char op;

    while(scanf("%d", &n), n){
        scanf("%d", &ans);

        while(--n){
            scanf("%c%d", &op, &num);

            if(op == '+')
                ans += num;
            else
                ans -= num;
        }

        printf("Teste %d\n%d\n\n", test++, ans);
    }

    return 0;
}

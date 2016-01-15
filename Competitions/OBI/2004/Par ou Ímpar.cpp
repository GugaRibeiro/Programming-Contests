/*Implementação
**O(n)*/

/*Usei o operador unário '&' para verificar se um número é par ou ímpar,
**ele é mais rápido porquê não precisa realizar de fato a operação de
**divisão, apenas verificar se o bit menos significativo está como 0, ou
**seja o número é par, ou como 1, quando ele será ímpar*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    string a, b;
    int x, y, n, test = 1;

    while(scanf("%d", &n), n){

        getchar();
        cin >> a; cin >> b;

        printf("Teste %d\n", test++);
        while(n--){
            scanf("%d %d", &x, &y);

            if((x + y) & 1)
                puts(b.c_str());
            else
                puts(a.c_str());

        }
        putchar('\n');
    }

    return 0;
}

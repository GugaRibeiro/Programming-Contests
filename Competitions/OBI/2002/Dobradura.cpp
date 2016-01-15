/*Matemática*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, test = 1, ans;

    while(scanf("%d", &n), n != -1){
        ans = ((1 << n) + 1);
        printf("Teste %d\n%d\n\n", test++, ans * ans);
    }

    return 0;
}

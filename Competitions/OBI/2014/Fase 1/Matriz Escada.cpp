/*Implementação, princípio da Programação Dinâmica*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    int val, n, m, zero_column = -1, left_non_zero;;
    bool ans = true;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        left_non_zero = m;

        for(int j = 0; j < m; j++){
            scanf("%d", &val);

            if(val){
                if(j <= zero_column)
                    ans = false;
                if(left_non_zero == m)
                    left_non_zero = j;
            }
        }
        zero_column = left_non_zero;
    }

    puts(ans ? "S" : "N");

    return 0;
}

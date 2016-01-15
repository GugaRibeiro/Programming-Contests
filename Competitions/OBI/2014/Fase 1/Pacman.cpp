/*Implementaçaõ*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    string tab[110];
    int n;

    scanf("%d ", &n);

    for(int i = 0; i < n; i++)
        cin >> tab[i];

    int ans = 0, aux = 0;

    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            for(int j = 0; j < n; j++){
                if(tab[i][j] == 'o')
                    aux++;
                else if(tab[i][j] == 'A')
                    aux = 0;
                ans = max(ans, aux);
            }
        }else{
            for(int j = n - 1; j >= 0; j--){
                if(tab[i][j] == 'o')
                    aux++;
                else if(tab[i][j] == 'A')
                    aux = 0;
                ans = max(ans, aux);
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}

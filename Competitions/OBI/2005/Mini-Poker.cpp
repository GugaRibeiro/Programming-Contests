/*Implementação*/

#include <bits/stdc++.h>

using namespace std;

int main(){
 
    int n, val, vet[20], ans;
 
    scanf("%d", &n);
 
    for(int j = 1; j <= n; j++){
        memset(vet, 0, sizeof vet);
 
        for(int i = 0; i < 5; i++){
            scanf("%d", &val);
            vet[val]++;
        }
 
        int q = 0;
 
        for(int i = 1; i < 20; i++)
            if(vet[i] != 0)
                q++;
 
        if(q == 5){
 
            bool seq = true;
            int aux[5], cont = 0;
 
            for(int i = 1; i < 20; i++)
                if(vet[i] != 0)
                    aux[cont++] = i;
 
            for(int i = 1; i < 5; i++)
                if(aux[i] - aux[i - 1] != 1)
                    seq = false;
 
            if(seq)
                ans = aux[0] + 200;
            else
                ans = 0;
        }
        else if(q == 4){
 
            for(int i = 1; i < 20; i++)
                if(vet[i] == 2)
                    ans = i;
        }
        else if(q == 3){
 
            ans = 0;
 
            for(int i = 1; i < 20; i++)
                if(vet[i] == 3)
                    ans = i + 140;
 
            if(ans == 0){
 
                int x, y = 0;
 
                for(int i = 1; i < 20; i++){
                    if(vet[i] == 2 && y == 0)
                        y = i;
                    else if(vet[i] == 2 && y != 0)
                        x = i;
                }
 
                ans = (3 * x) + (2 * y) + 20;
            }
        }
        else{
 
            for(int i = 1; i < 20; i++)
                if(vet[i] == 4)
                    ans = i + 180;
 
            for(int i = 1; i < 20; i++)
                if(vet[i] == 3)
                    ans = i + 160;
        }
 
        printf("Teste %d\n%d\n\n", j, ans);
    }

    return 0;
}

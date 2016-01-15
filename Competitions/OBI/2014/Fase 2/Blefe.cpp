/*Dois ponteiros, Busca Binária, Implementação*/

#include <bits/stdc++.h>

using namespace std;

int A[1010], B[10010], ini, fim;

bool find_sum(int val){
    int i = ini, j = fim - 1;

    while(i <= j){
        if(B[i] + B[j] > val){
            j--;
        }else if(B[i] + B[j] < val){
            i++;
        }else{
            return true;
        }
    }

    return false;
}

int main(){

    int n, m, val, pos;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    sort(A, A + n);

    while(m--){
        scanf("%d", &val);

        if(!binary_search(A, A + n, val) && !find_sum(val)){
            printf("%d\n", val);
            //na OBI eu serei mais prudente :v
            return 0;
        }

        pos = lower_bound(B, B + fim, val) - B;

        for(int i = fim; i > pos; i--)
            swap(B[i], B[i - 1]);

        B[pos] = val;

        fim++;
    }

    puts("sim");

    return 0;
}

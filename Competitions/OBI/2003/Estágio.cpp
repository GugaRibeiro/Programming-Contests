/*Implementação
**O(n)*/

#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> ii;

int main(){
    int n, _max, test = 1;
    ii alunos[1010];

    while(scanf("%d", &n), n){
        _max = 0;

        for(int i = 0; i < n; i++){
            scanf("%d %d", &alunos[i].first, &alunos[i].second);
            _max = max(_max, alunos[i].second);
        }

        printf("Turma %d\n", test++);

        for(int i = 0; i < n; i++){
            if(alunos[i].second == _max){
                printf("%d ", alunos[i].first);
            }
        }
        puts("\n");
    }

    return 0;
}

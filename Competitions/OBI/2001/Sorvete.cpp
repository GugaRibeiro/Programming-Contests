/*Geometria / Algoritmo Guloso
**Segmentos de reta
**O(n) + O(n log n)*/

#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> ii;

int main(){

    int p, s, ini, fim, test = 1;
    ii seg[5010];
    vector <ii> ans;

    while(scanf("%d %d", &p, &s), p){
        for(int i = 0; i < s; i++){
            scanf("%d %d", &ini, &fim);
            seg[i] = make_pair(ini, fim);
        }

        sort(seg, seg + s);

        ini = seg[0].first;
        fim = seg[0].second;

        for(int i = 0; i < s; i++){
            if(seg[i].first > fim){
                ans.push_back(make_pair(ini, fim));

                ini = seg[i].first;
                fim = seg[i].second;
            }else if(fim < seg[i].second){
                fim = seg[i].second;
            }
        }

        ans.push_back(make_pair(ini, fim));

        printf("Teste %d\n", test++);

        for(int i = 0; i < ans.size(); i++){
            printf("%d %d\n", ans[i].first, ans[i].second);
        }
        putchar('\n');

        ans.clear();
    }

    return 0;
}

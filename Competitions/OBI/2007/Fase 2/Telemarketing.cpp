/*Implementação, STL*/

/*O que eu aprendi com essa questão? Que na OBI em nenhuma instância devo usar entrada e saída por stream (cin, cout) :v*/
#include <bits/stdc++.h>

using namespace std;

typedef struct seller{
    int id, time;

    seller() {}
    seller(int i, int t): id(i), time(t){}

    inline bool operator < (const seller &other) const{
        if(time == other.time) return id > other.id;
        return time > other.time;
    }
}seller;

int ans[1010];

int main(){
    int s, c, t;
    seller aux;
    priority_queue <seller> pq;

    scanf("%d %d", &s, &c);

    for(int i = 1; i <= s; i++)
        pq.push(seller(i, 0));

    while(c--){
        scanf("%d", &t);

        aux = pq.top();
        pq.pop();

        ans[aux.id]++;
        aux.time += t;
        pq.push(aux);
    }

    for(int i = 1; i <= s; i++)
        printf("%d %d\n", i, ans[i]);

    return 0;
}

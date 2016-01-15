/*Grafos / Breadth-First Search
**O(V + E)*/

/*OBS.: Tomar cuidado com o caso onde só há um vértice no grafo*/

#include <bits/stdc++.h>

const int MAXV = 60;
const int INF = 1000000;

using namespace std;

bool mat[MAXV][MAXV];
int dist[MAXV];

void bfs(int s, int v){
    queue <int> q;

    dist[s] = 0;
    q.push(s);

    while(!q.empty()){
        s = q.front();
        q.pop();

        for(int i = 0; i < v; i++){
            if(mat[s][i] and dist[i] == INF){
                dist[i] = dist[s] + 1;
                q.push(i);
            }
        }
    }
}

int main(){

    int v, e, s, p, a, b, test = 1;
    vector <int> ans;

    while(scanf("%d %d %d %d", &v, &e, &s, &p), v){
        s--;
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                mat[i][j] = false;
            }
            dist[i] = INF;
        }

        while(e--){
            scanf("%d %d", &a, &b);
            a--; b--;
            mat[a][b] = mat[b][a] = true;
        }

        bfs(s, v);

        printf("Teste %d\n", test++);

        for(int i = 0; i < v; i++){
            if(dist[i] != INF and i != s and dist[i] <= p)
                ans.push_back(i + 1);
        }

        for(int i = 0; i < ans.size(); i++){
            printf("%d ", ans[i]);
        }
        puts("\n");

        ans.clear();
    }

    return 0;
}

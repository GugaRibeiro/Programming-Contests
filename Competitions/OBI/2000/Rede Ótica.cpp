//Grafos: Minimum Spanning Tree / Union-Find Disjoint-Sets
//Kruskal's Algorithm / O(E * log E)

#include <bits/stdc++.h>

const int MAXV = 110;

using namespace std;

int id[MAXV], _rank[MAXV];
vector <pair<int, pair<int, int> > > edges;

int find_set(int x){
    if(id[x] == x) return x;
    return id[x] = find_set(id[x]);
}

bool union_set(int x, int y){
    int i = find_set(x),
        j = find_set(y);

    if(i != j){
        if(_rank[i] > _rank[j]){
            id[j] = i;
            _rank[i] += _rank[j];
        }else{
            id[i] = j;
            _rank[j] += _rank[i];
        }
        return true;
    }
    return false;
}

int main(){

    int v, e, test = 1, x, y, w, cnt;

    while(scanf("%d %d", &v, &e), v){
        cnt = 0;
        for(int i = 1; i <= v; i++){
            id[i] = i;
            _rank[i] = 0;
        }

        while(e--){
            scanf("%d %d %d", &x, &y, &w);
            edges.push_back(make_pair(w, make_pair(x, y)));
        }

        sort(edges.begin(), edges.end());

        printf("Teste %d\n", test++);

        for(int i = 0; i < edges.size() and cnt < v - 1; i++){
            x = edges[i].second.first; y = edges[i].second.second;

            if(union_set(x, y)){
                printf("%d %d\n", min(x, y), max(x, y));
                cnt++;
            }
        }
        putchar('\n');
        edges.clear();
    }

    return 0;
}

//Grafos: Minimum Spanning Tree
//Prim's Algorithm / O(E * log V)

#include <bits/stdc++.h>

const int MAXV = 110;

using namespace std;

typedef pair <int, int> ii;
typedef pair<int, pair<int, int> > iii;

vector <ii> adj[MAXV];
priority_queue <iii, vector<iii>, greater<iii> > pq;
bool mark[MAXV];

void process(int vtx){
    int y, w;
    mark[vtx] = true;

    for(int i = 0; i < adj[vtx].size(); i++){
        w = adj[vtx][i].second; y = adj[vtx][i].first;
        pq.push(make_pair(w, make_pair(vtx, y)));
    }
}

void prim(int v){

    iii aux;
    int x, y;

    process(1);

    while(!pq.empty()){
        aux = pq.top();
        pq.pop();

        x = aux.second.first;
        y = aux.second.second;

        if(!mark[y]){
            printf("%d %d\n", min(x, y), max(x, y));
            process(y);
        }
    }
}

int main(){

    int v, e, x, y, w, test = 1;

    while(scanf("%d %d", &v, &e), v){
        for(int i = 1; i <= v; i++){
            adj[i].clear();
            mark[i] = false;
        }

        while(e--){
            scanf("%d %d %d", &x, &y, &w);
            adj[x].push_back(make_pair(y, w));
            adj[y].push_back(make_pair(x, w));
        }

        printf("Teste %d\n", test++);

        prim(v);

        putchar('\n');
    }

    return 0;
}
 

/*Grafos: Breadth-First Search
**Ordenação / Implementação
**O(V + E) + O(V * log V) + O(n * 100 * log n)*/

#include <bits/stdc++.h>

const int MAXV = 110;
const int INF = 100000;

using namespace std;

typedef pair <int, pair<string, string> > iss;

map <string, int> a;

bool mat[MAXV][MAXV];
int dist[MAXV];

bool cmp(iss a, iss b){
    if(a.second.second == b.second.second){
        return a.second.first < b.second.first;
    }
    return a.second.second < b.second.second;
}

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

    int n, cont, len, x, y, test = 1;
    string line, name;
    vector <pair<string, int> > aux;
    vector <iss> ans;
    map <string, int>::iterator it;

    while(scanf("%d", &n), n){
        getchar();
        cont = 0;

        for(int i = 0; i < 110; i++){
            for(int j = 0; j < 110; j++){
                mat[i][j] = false;
            }
            dist[i] = INF;
        }

        while(n--){
            getline(cin, line);

            for(int i = 0; i < line.size() - 1; i++){
                if(line[i] != ','){
                    name += line[i];
                }else{
                    aux.push_back(make_pair(name, -1));
                    name.clear();
                    i++;
                }
            }

            aux.push_back(make_pair(name, -1));

            len = aux.size();

            for(int i = 0; i < len; i++){
                it = a.find(aux[i].first);
                if(it == a.end()){
                    a[aux[i].first] = cont;
                    aux[i].second = cont++;
                }else{
                    aux[i].second = it->second;
                }
            }

            for(int i = 0; i < len; i++){
                x = aux[i].second;
                for(int j = 0; j < len; j++){
                    y = aux[j].second;
                    mat[x][y] = mat[y][x] = true;
                }
            }

            name.clear();
            aux.clear();
        }

        for(it = a.begin(); it != a.end(); it++){
            if(it->first != "P. Erdos")
                ans.push_back(make_pair(it->second,
                              make_pair(it->first.substr(0, 1), it->first.substr(3, it->first.size()))));
        }

        printf("Teste %d\n", test++);

        sort(ans.begin(), ans.end(), cmp);

        it = a.find("P. Erdos");

        if(it == a.end()){
            for(int i = 0; i < ans.size(); i++){
                printf("%s. %s: infinito\n", ans[i].second.first.c_str(), ans[i].second.second.c_str());
            }
        }else{
            bfs(it->second, cont);

            for(int i = 0; i < ans.size(); i++){
                printf("%s. %s: ", ans[i].second.first.c_str(), ans[i].second.second.c_str());

                if(dist[ans[i].first] == INF)
                    puts("infinito");
                else
                    printf("%d\n", dist[ans[i].first]);
            }
        }

        putchar('\n');

        a.clear();
        ans.clear();
    }

    return 0;
}
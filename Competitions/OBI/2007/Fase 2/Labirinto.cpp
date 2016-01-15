/*BFS, Implementação*/

#include <bits/stdc++.h>

const int MAX = 60;

using namespace std;

typedef pair <pair<int, int>, int> iii;

int dx[] = {0, -1, 0, 1, 0},
    dy[] = {0, 0, 1, 0, -1},
    grid[MAX][MAX], dist[MAX][MAX][15];

int main(){
    int n, m, x, y, z, a, b, c, ans = INT_MAX;
    queue <iii> q;
    iii aux;

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> grid[i][j];
            for(int k = 0; k < 10; k++){
                dist[i][j][k] = -1;
            }
        }
    }

    q.push({{1, 1}, 0});
    dist[1][1][0] = 0;

    while(!q.empty()){
        aux = q.front();
        q.pop();

        x = aux.first.first; y = aux.first.second;
        z = aux.second;

        for(int i = 0; i < 5; i++){
            a = x + dx[i]; b = y + dy[i];
            c = (z + 1) % 10;

            if(a < 1 || a > n || b < 1 || b > m) continue;

            if(dist[a][b][c] == -1 && (grid[a][b] + z) % 10 - 1 <= (grid[x][y] + z) % 10){
                dist[a][b][c] = dist[x][y][z] + 1;
                q.push({{a, b}, c});
            }
        }
    }

    for(int i = 0; i < 10; i++)
        ans = min(ans, dist[n][m][i]);

    cout << ans << "\n";

    return 0;
}

/*APSP - Floyd-Warshall's Algorithm O(n³)*/

#include <bits/stdc++.h>

const int MAXN = 1010;
const int INF = (int)1e8;

using namespace std;

int mat[MAXN][MAXN];
int t[MAXN];

void warshall(int n){
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			}
		}
	}
}

int main(){
	int n, e, u, v, w;

	scanf("%d %d", &n, &e);

	for(int i = 1; i <= n; i++){
		scanf("%d", &t[i]);
		for(int j = 1; j <= n; j++){
			mat[i][j] = INF;
		}
	}

	while(e--){
		scanf("%d %d %d", &u, &v, &w);
		mat[u][v] = w + t[v];
	}

	warshall(n);

	int ans = INF;

	for(int i = 1; i <= n; i++){
	    for(int j = 1; j <= n; j++){
			ans = min(ans, mat[i][j] + mat[j][i]);
		}
	}

	printf("%d\n", ans);

	return 0;
}

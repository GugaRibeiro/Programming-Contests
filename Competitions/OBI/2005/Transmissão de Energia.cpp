/*Grafos, Grafo fortemente conexo (adirecionado)
 *O(V + E)*/

#include <bits/stdc++.h>

const int MAXV = 110;

using namespace std;

vector <int> adj[MAXV];
bool mark[MAXV];

void dfs(int idx){
	mark[idx] = true;
	
	for(int i = 0; i < (int)adj[idx].size(); i++){
		int j = adj[idx][i];
		
		if(!mark[j])
			dfs(j);;
	}
}

int main(){
	int v, e, test = 1, x, y, ans;
	
	while(scanf("%d %d", &v, &e), v){
		for(int i = 0; i < v; i++){
			adj[i].clear();
			mark[i] = false;
		}
		
		while(e--){
			scanf("%d %d", &x, &y);
			x--; y--;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		ans = 0;
		
		for(int i = 0; i < v; i++){
			if(!mark[i]){
				ans++;
				dfs(i);
			}
		}
				
		printf("Teste %d\n%s\n\n", test++, ans == 1 ? "normal" : "falha");
	}
	
	return 0;
}

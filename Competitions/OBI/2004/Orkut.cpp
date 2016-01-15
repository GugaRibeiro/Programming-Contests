/*Grafos: Ordenação Topológica
 *O(V + E)*/

#include <bits/stdc++.h>

const int MAXV = 40;

using namespace std;

map <string, int> si;
vector <int> adj[MAXV], top;

bool hasCycle;
int mark[MAXV];

void dfs(int idx){
	mark[idx] = 1;
	
	for(int i = 0; i < (int)adj[idx].size(); i++){
		int j = adj[idx][i];
		
		if(!mark[j]){
			dfs(j);
		}else if(mark[j] == 1){
			hasCycle = true;
		}
	}
	
	mark[idx] = 2;
	top.push_back(idx);
}

int main(){
		
	int v, e, tc = 1, x, y;
	string names[MAXV], name, aux;
		
	while(scanf("%d", &v), v){
		getchar();
		
		for(int i = 0; i < v; i++){
			cin >> names[i];
			si[names[i]] = i;
			
			adj[i].clear();
			mark[i] = 0;
		}
		
		for(int i = 0; i < v; i++){
			cin >> name >> e; getchar();
			x = si[name];
			while(e--){
				cin >> aux;
				y = si[aux];
				
				adj[y].push_back(x);
			}
		}
		
		hasCycle = false;
		
		for(int i = 0; i < v; i++){
			if(!mark[i])
				dfs(i);
		}
		
		printf("Teste %d\n", tc++);
		
		if(hasCycle){
			puts("impossivel\n");
		}else{
			
			reverse(top.begin(), top.end());
			
			for(int i = 0; i < v; i++)
				printf("%s ", names[top[i]].c_str());
			
			puts("\n");
		}	
	
		si.clear();
		top.clear();
	}
	
	return 0;
}

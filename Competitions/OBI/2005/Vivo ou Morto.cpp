/*Implementação
*O(R * N)*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n, r, x, test = 1, aux, flag;
	queue <int> q;
	
	while(scanf("%d %d", &n, &r), n){
		for(int i = 0; i < n; i++){
			scanf("%d", &x);
			q.push(x);
		}
		
		while(r--){
			scanf("%d %d", &n, &flag);
			
			for(int i = 0; i < n; i++){
				scanf("%d", &x);
				
				aux = q.front();
				q.pop();
				
				if(x == flag){
					q.push(aux);
				}
			}
		}
		
		printf("Teste %d\n%d\n\n", test++, q.front());
		
		q = queue <int>();
	}
	
	return 0;
}

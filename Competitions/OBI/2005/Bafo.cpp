/*Implementação
 *O(n)*/
 
#include <bits/stdc++.h>

using namespace std;

int main(){
 
	int a, b, x, y, n, test = 1;
 
	while(scanf("%d", &n), n){
		a = b = 0;
		while(n--){
			scanf("%d %d", &x, &y);
			a += x;
			b += y;
		}
	
		printf("Teste %d\n", test++);
	
		if(a > b){
			puts("Aldo\n");
		}else{
			puts("Beto\n");
		}
	}
 
	return 0;
}

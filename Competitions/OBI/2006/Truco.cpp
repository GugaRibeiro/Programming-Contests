/*Implementação*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int m[14], vet[10], n, x, y, a = 0, b = 0;
	
	m[4] = 1; m[5] = 2;
	m[6] = 3; m[7] = 4;
	m[12] = 5; m[11] = 6;
	m[13] = 7; m[1] = 8;
	m[2] = 9; m[3] = 10;
	
	scanf("%d", &n);
	
	while(n--){
		x = y = 0;
		
		for(int i = 0; i < 6; i++)
			scanf("%d", &vet[i]);
			
		for(int i = 0; i < 3; i++){
			if(m[vet[i]] > m[vet[3 + i]]){
				x++;
			}else if(m[vet[i]] < m[vet[3 + i]]){
				y++;
			}
		}
		
		if(x >= y){
			a++;
		}else{
			b++;
		}
	}
	
	printf("%d %d\n", a, b);
	
	return 0;
}

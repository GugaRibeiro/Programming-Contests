/*Implementação
 *O(n)*/

/*Um pouco chato, porém bastante simples*/

#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int senha[15][6][2], n, freq[11], test = 1, ans[6];
	char code[15][7];
	
	while(scanf("%d", &n), n){
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 5; j++){
				scanf("%d %d", &senha[i][j][0], &senha[i][j][1]);
			}
			
			for(int j = 0; j < 6; j++)
				scanf(" %c", &code[i][j]);
		}
		
		for(int i = 0; i < 6; i++){
			memset(freq, 0, sizeof freq);
			for(int j = 0; j < n; j++){
				freq[senha[j][code[j][i] - 'A'][0]]++;
				freq[senha[j][code[j][i] - 'A'][1]]++;
			}
			
			for(int j = 0; j < 10; j++){
				if(freq[j] == n){
					ans[i] = j;
					break;
				}
			}
		}
		
		printf("Teste %d\n", test++);
		
		for(int i = 0; i < 6; i++)
			printf("%d ", ans[i]);
			
		puts("\n");
	}
	
	return 0;
}

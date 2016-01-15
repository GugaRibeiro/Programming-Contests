/*Programação Dinâmica, Knapsack 0-1
**O(f * c) */

#include <bits/stdc++.h>

const int MAXF = 60;
const int MAXC = 1010;

using namespace std;

int t[MAXF], d[MAXF],
	memo[MAXF][MAXC], f;

int dp(int i, int rem){
	if(i == f)
		return 0;
	
	int &ret = memo[i][rem];
	
	if(ret != -1)
		return ret;
	
	return ret = max(dp(i + 1, rem), rem >= t[i] ? 
					 dp(i + 1, rem - t[i]) + d[i] : 0);
}

int main(){
	
	int c, test = 1;
	
	while(scanf("%d %d", &c, &f), c){
		for(int i = 0; i < f; i++){
			scanf("%d %d", &t[i], &d[i]);
			for(int j = 0; j <= c; j++)
				memo[i][j] = -1;
		}
		
		printf("Teste %d\n%d\n\n", test++, dp(0, c));
	}
	
	return 0;
}

/*Programação Dinâmica - Implementação
**2D Max Sum Range, como nesse caso o tamanho das submatrizes é estipulado na entrada
**podemos calcular qual submatriz de soma máxima em tempo quadrático, devido ao auxílio da
**matriz acumulativa e do princípio de inclusão e exclusão que nos permite saber o valor de uma
**submatriz em O(1)
**O(l * c) */

#include <bits/stdc++.h>

const int MAX = 1010;

using namespace std;

int caju[MAX][MAX];

int main(){
	int l, c, m, n, aux, ans;

	scanf("%d %d %d %d", &l, &c, &m, &n);

	for(int i = 1; i <= l; i++){
		for(int j = 1; j <= c; j++){
			scanf("%d", &caju[i][j]);
			caju[i][j] += caju[i - 1][j] + caju[i][j - 1] - caju[i - 1][j - 1];
		}
	}

	ans = 0;

	for(int i = m; i <= l; i++){
		for(int j = n; j <= c; j++){
			aux = caju[i][j] - caju[i - m][j] -
				  caju[i][j - n] + caju[i - m][j - n];

			ans = max(aux, ans);
		}
	}

	printf("%d\n", ans);

	return 0;
}

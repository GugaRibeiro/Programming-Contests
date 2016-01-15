/*Greedy*/

#include <bits/stdc++.h>

const int MAXN = 100010;

using namespace std;

int vet[MAXN];

int main(){
	int n, v;

	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &v);
		vet[v] = i;
	}

	int ans = 1;

	for(int i = 1; i < n; i++){
		if(vet[i] > vet[i + 1])
			ans++;
	}

	printf("%d\n", ans);

	return 0;
}

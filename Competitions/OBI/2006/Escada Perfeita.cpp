/*Mathematics: Arithmetic Sequence*/

#include <bits/stdc++.h>

using namespace std;

vector <int> b;

int main(){
	int n, q, sn = 0;

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &q);
		b.push_back(q);

		sn += q;
	}

	int an = ((2 * sn / n) + (n - 1)) / 2;
	int a1 = an - n + 1;

	int rem = 0, ans = 0;

	for(int i = 0; i < n; i++){
		rem += b[i] - (i + a1);

		if(b[i] > i + a1){
			ans += b[i] - (i + a1);
		}
	}

	printf("%d\n", rem ? -1 : ans);

	return 0;
}

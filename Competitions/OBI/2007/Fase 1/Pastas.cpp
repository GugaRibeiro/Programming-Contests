/*Implementação*/

#include <bits/stdc++.h>

const int MAXP = 1010;

using namespace std;

int f[MAXP];

int main(){
    int p, n, v;
    bool ans = true;

    cin >> p >> n;

    while(n--){
        cin >> v;
        f[v]++;
    }

    for(int i = 2; i <= p && ans; i++)
        if(f[i] > f[i - 1] || f[1] - f[i] > 1) ans = false;

    puts(ans ? "S" : "N");

    return 0;
}

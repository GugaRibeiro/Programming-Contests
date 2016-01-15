/*Programação Dinâmica, Algoritmo de Kadane, Implementaçaõ*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, val, sum = 0,
        in = 0, a_in = 0,
        out = 0, a_out = 0;

    cin >> n;

    while(n--){
        cin >> val;
        sum += val;

        a_in = max(val + a_in, 0);
        in = max(in, a_in);

        a_out = max(-val + a_out, 0);
        out = max(out, a_out);
    }

    cout << max(in, sum + out) << "\n";

    return 0;
}

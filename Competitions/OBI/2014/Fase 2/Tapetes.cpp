/*Algoritmo Guloso*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    long long l, n;

    cin >> l >> n;

    n--;

    cout << (l - n) * (l - n) + n << "\n";

    return 0;
}

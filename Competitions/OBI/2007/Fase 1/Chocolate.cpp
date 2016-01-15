/*Implementação*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, v, ans = 0;

    cin >> n;

    while(n--){
        cin >> v;
        ans += v - 1;
    }

    cout << ans << "\n";

    return 0;
}

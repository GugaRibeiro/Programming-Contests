/*Implementação*/

#include <bits/stdc++.h>

using namespace std;

main(){
    int C, cont = 0;
    string pal;
    cin>>C>>pal;
    for(int i = 0; i < C; i++){
        if(pal[i] == 'P')cont += 2;
        else if(pal[i] == 'C')cont += 2;
        else if(pal[i] == 'A')cont++;
    }
    cout<<cont;
}

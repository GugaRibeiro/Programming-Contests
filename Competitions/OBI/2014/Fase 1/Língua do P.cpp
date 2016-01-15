/*Implementação*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    string text;
    bool ok = false;

    getline(cin, text);

    int len = text.size();

    for(int i = 0; i < len; i++){
        if(text[i] == ' '){
            putchar(' ');
        }else if(ok){
            putchar(text[i]);
            ok = false;
        }else{
            ok = true;
        }
    }

    putchar('\n');

    return 0;
}

/*Implementação, STL*/
/*O que essa questão me ensinou? A não usar auto na OBI :v*/

#include <bits/stdc++.h>

using namespace std;

map <int, int> app, pc;

int main(){
    int c, n, id, version;

    cin >> c >> n;

    while(c--){
        cin >> id >> version;
        pc[id] = version;
    }

    while(n--){
        cin >> id >> version;
        if(app.find(id) != app.end()){
            if(app[id] < version){
                app[id] = version;
            }
        }else if(pc.find(id) == pc.end() || pc[id] < version){
            app[id] = version;
        }
    }

    //for(auto i : app)
    for(map <int, int>::iterator i = app.begin(); i != app.end(); i++)
        printf("%d %d\n", i->first, i->second);

    return 0;
}

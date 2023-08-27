#include <bits/stdc++.h>
#define max(a, b) (a > b)? a: b
using namespace std;
int main(){
    int n, num, res, aux;
    while(cin >> n && n){
        res = aux = 0;
        for(int i = 0; i < n; i++){
            cin >> num;
            aux += num;
            res = max(aux, res);
            if(aux < 0) aux = 0;
        }
        if(res > 0) cout << "MRS = " << res << endl; 
        else cout << "Negativo" << endl;
    }
    return 0;
}

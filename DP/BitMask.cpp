#include <bits/stdc++.h>
using namespace std;
void mask(int n, int ar[]){
    int l = 1 << n;
    for(int i = 0; i < l; i++){
        for(int j = 0; j < n; j++)
            if(i & (1 << j))
                cout << ar[j] << " ";
        cout << endl;
    }
}

int main(){
    int n;
    cin >> n;
    int ar[n];
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    mask(n, ar);
    return 0;
}

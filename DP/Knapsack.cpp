#include <bits/stdc++.h>
using namespace std;
// NosNerfearon();
int ganancia[100] = {100, 70, 50, 10};
int peso[100] = {10, 4, 6, 12};
// Iterativo
int knapsack(int cap, int n) {// Capacidad y cantidad.
    int dp[n+1][cap+1];
    for(int i = 0; i <= n; i++)// Recorrer objetos
        for(int j = 0; j <= cap; j++){
            if(i == 0 || j == 0) dp[i][j] = 0;// Caso base
            else if(peso[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], ganancia[i - 1] + dp[i - 1][j - peso[i - 1]]);
            else dp[i][j] = dp[i - 1][j];
        }
    return dp[n][cap];
}
int N = 4;
int memo[100][50];//objetos-capacidad
//Recursivo
int mochila(int obj, int cap){//Top-Down
    if(cap == 0 || obj == N) return 0;
    if(memo[obj][cap] != -1) return memo[obj][cap];
    if(peso[obj] > cap) return mochila(obj + 1, cap);
    else
        return max(mochila(obj + 1, cap), ganancia[obj] + mochila(obj + 1, cap - peso[obj]));
}
signed main() {
    //memset(memo, -1, sizeof(memo));
    //cout << mochila(0, 12);
    cout << knapsack(12, 4) << endl;
    cout << flush;
}

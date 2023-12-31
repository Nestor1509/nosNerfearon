#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl '\n'
#define ff first
#define ss second
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, MOD) for (int i = n; i <= MOD; i++)
#define rfor(i, n) for (int i = n - 1; i >= 0; i--)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) int(x.size())
#define pii pair<int, int>
#define vi vector<int>
#define vpi vector<pair<int, int>>
#define ms(x, n) memset(x, n, sizeof(x))
#define find(x, n) find(all(x), n) != x.end()
#define suma(a, b) ((a % MOD) + (b % MOD)) % MOD
#define resta(a, b) ((a % MOD) - (b % MOD)) % MOD
#define mult(a, b) ((a % MOD) * (b % MOD)) % MOD
#define div(a, b) ((a % MOD) * (modularInverse(b, MOD))) % MOD
//" \n"[i == n - 1]
using namespace std;
// NosNerfearon();
const int MOD = 1e9 + 7;
struct matrix {
  int n, m;
  vector<vector<int>> v;

  matrix(int n, int m, bool ones = false) : n(n), m(m), v(n, vector<int>(m)) {
    if (ones) forn (i, n) v[i][i] = 1;
  }

  matrix operator * (const matrix &o) {
    matrix ans(n, o.m);
    forn (i, n)
      forn (k, m) if (v[i][k])
        forn (j, o.m)
          ans[i][j] = (v[i][k] * o.v[k][j] + ans[i][j]) % MOD;
    return ans;
  }

  vector<int> & operator [] (int i) {
    return v[i];
  }
};

matrix binpow(matrix b, int e) {
  matrix ans(b.n, b.m, true);
  while (e) {
    if (e & 1) ans = ans * b;
    b = b * b;
    e >>= 1;
  }
  return ans;
}
signed main() {

    /*
    Tomemos como ejemplo si = si−1 + si−2 + 1
    si − si−1 = si−1 + si−2 + 1 − (si−2 + si−3 + 1)
    */
  
    matrix a(4, 4), b(4, 4);
    a[0][0] = 4;
    a[0][1] = (-1 + MOD) % MOD;
    a[0][2] = (-1 + MOD) % MOD;
    a[0][3] = (-1 + MOD) % MOD;
    forn(i, 3) a[i + 1][i] = 1;

    b[0][0] = 17;
    b[1][0] = 3;
    b[2][0] = 2;
    b[3][0] = 1;

    int n; cin >> n;
    if(n < 4){
        cout << b[3 - n][0] << endl;
    }else{
        matrix ans = binpow(a, n - 3) * b;
        cout << ans[0][0] << endl;
    }

    cout << flush;
}

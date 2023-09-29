#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl '\n'
#define ff first
#define ss second
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m, x) for (int i = n; i < m; i += x)
#define rfor(i, n) for (int i = n - 1; i >= 0; i--)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) int(x.size())
#define pii pair<int, int>
#define vi vector<int>
#define vpi vector<pair<int, int>>
#define ms(x, n) memset(x, n, sizeof(x))
#define suma(a, b) ((a % MOD) + (b % MOD)) % MOD
#define resta(a, b) ((a % MOD) - (b % MOD)) % MOD
#define mult(a, b) ((a % MOD) * (b % MOD)) % MOD
#define div(a, b) ((a % MOD) * (modularInverse(b, MOD))) % MOD
//" \n"[i == n - 1]
using namespace std;
// NosNerfearon();
const int inf = 2e9;
signed main() {
  fast
  int n, k; cin >> n >> k;
  vi a(n);
  forn(i, n){
    char x; cin >> x;
    a[i] = x - '0';
  }
  sort(all(a));
  int digit = n / k, mx = n % k;
  int ans = INT_MAX;
  do{
    vi num(k, 0); int c = 0;
    for(int i = 0; i < n;){
      int d = digit + (c < mx), aux = i;
      for(int j = i; j < aux + d; j++){
        num[c] = num[c] * 10 + a[i++];
      }
      c++;
    }
    sort(all(num));
    ans = min(ans, num[k - 1]);
  }while(next_permutation(all(a))); // O(n! * n)
  cout << ans << endl;
  cout << flush;
}

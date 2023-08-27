const ll maxn = 1000002;
ll mod = 1000000007;
ll inv[maxn];
//Exponenciación Binaria
ll binpow(ll a, ll b, ll m) {
  a %= m;
  int res = 1;
  while (b) {
    if (b & 1) res = (res*a)%m;
    a = (a*a)%m;
    b >>= 1;
  }
  return res;
}
//Calcular inversos
void invs() {
    ll v = 1;
    form(i, 1, maxn, 1) {
        inv[i] = v;
        v = (v * i) % mod;
    }
    ll x = binpow(v, mod-2, mod);
    for(ll i = maxn-1; i >= 1; --i) {
        inv[i] = (x * inv[i]) % mod;
        x = (x * i) % mod;
    }
}


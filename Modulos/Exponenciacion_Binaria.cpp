ll binex(ll a, ll b){//O(log(p))
    ll ans = 1;
    while (b){
        if (b & 1){
            ans *= a;
            ans %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ans;
}

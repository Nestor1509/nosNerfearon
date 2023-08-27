tuple<ll, ll, ll> extendedGcd(ll a, ll b){
    if(b == 0){
        if(a > 0) return {a, 1, 0};
        else return {-a, -1, 0};
    } else {
        auto[d, x, y] = extendedGcd(b, a % b);
        return {d, y, x - y * (a / b)};
    }
}

ll modularInverse(ll a, ll m){
    auto[d, x, y] = extendedGcd(a, m);
    if(d != 1) return -1; // inverse doesn't exist
    if(x < 0) x += m;
    return x;
}

ll powerMod(ll b, ll e, ll m){
    ll ans = 1;
    b %= m;
    if(e < 0){
        b = modularInverse(b, m);
        e = -e;
    }
    while(e){
        if(e & 1) ans = ans * b % m;
        e >>= 1;
        b = b * b % m;
    }
    return ans;
}

bool isPrimeMillerRabin(ll n){
    if(n < 2) return false;
    if(!(n & 1)) return n == 2;
    ll d = n - 1, s = 0;
    for(; !(d & 1); d >>= 1, ++s);
    for(int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
        if(n == a) return true;
        ll m = powerMod(a, d, n);
        if(m == 1 || m == n - 1) continue;
        int k = 0;
        for(; k < s; ++k){
            m = m * m % n;
            if(m == n - 1) break;
        }
        if(k == s) return false;
    }
    return true;
}

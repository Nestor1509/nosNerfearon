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

//(a/b) mod m
int div = ((a % m) * (modularInverse(b, m))) % m;

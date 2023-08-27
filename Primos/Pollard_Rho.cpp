//PollarRho O(3√n)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll aleatorio(ll a, ll b){
	std::uniform_int_distribution<ll> dist(a, b);
	return dist(rng);
}

ll getFactor(ll n){
	ll a = aleatorio(1, n - 1), b = aleatorio(1, n - 1);
	ll x = 2, y = 2, d = 1;
	while(d == 1){
		x = x * ((x + b) % n) % n + a;
		y = y * ((y + b) % n) % n + a;
		y = y * ((y + b) % n) % n + a;
		d = gcd(abs(x - y), n);
	}
	return d;
}

tuple<ll, ll, ll> extendedGcd(ll a, ll b){
	if(b == 0){
		if(a > 0) return {a, 1, 0};
		else return {-a, -1, 0};
	}else{
		auto[d, x, y] = extendedGcd(b, a%b);
		return {d, y, x - y*(a/b)};
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

map <ll, ll > fact;
void PollardRho(ll n, bool clean = true){
	if(clean) fact.clear();
	while(n > 1 && !isPrimeMillerRabin(n)){
		ll f = n;
		for(; f == n; f = getFactor(n));
		n /= f;
		PollardRho(f, false);
		for(auto&[p, a] : fact){
			while(n % p == 0){
				n /= p;
				++a;
			}
		}
	}
	if(n > 1) ++fact[n];
}

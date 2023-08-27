#include <bits/stdc++.h>
using namespace std;
using lli = __int128_t;

lli piso(lli a, lli b){
	if((a >= 0 && b > 0) || (a < 0 && b < 0)){
		return a / b;
	}else{
		if(a % b == 0) return a / b;
		else return a / b - 1;
	}
}

lli techo(lli a, lli b){
	if((a >= 0 && b > 0) || (a < 0 && b < 0)){
		if(a % b == 0) return a / b;
		else return a / b + 1;
	}else{
		return a / b;
	}
}

lli power(lli b, lli e){
	lli ans = 1;
	while(e){
		if(e & 1) ans *= b;
		e >>= 1;
		b *= b;
	}
	return ans;
}

lli multMod(lli a, lli b, lli n){
	lli ans = 0;
	a %= n, b %= n;
	if(abs(b) > abs(a)) swap(a, b);
	if(b < 0){
		a = -a, b = -b;
	}
	while(b){
		if(b & 1) ans = (ans + a) % n;
		b >>= 1;
		a = (a + a) % n;
	}
	return ans;
}

lli gcd(lli a, lli b){
	lli r;
	while(b != 0) r = a % b, a = b, b = r;
	return a;
}

lli lcm(lli a, lli b){
	return b * (a / gcd(a, b));
}

lli gcd(const vector<lli>& nums){
	lli ans = 0;
	for(lli num : nums) ans = gcd(ans, num);
	return ans;
}

lli lcm(const vector<lli>& nums){
	lli ans = 1;
	for(lli num : nums) ans = lcm(ans, num);
	return ans;
}

tuple<lli, lli, lli> extendedGcd(lli a, lli b){
	if(b == 0){
		if(a > 0) return {a, 1, 0};
		else return {-a, -1, 0};
	}else{
		auto[d, x, y] = extendedGcd(b, a%b);
		return {d, y, x - y*(a/b)};
	}
}

lli modularInverse(lli a, lli m){
	auto[d, x, y] = extendedGcd(a, m);
	if(d != 1) return -1; // inverse doesn't exist
	if(x < 0) x += m;
	return x;
}







lli powerMod(lli b, lli e, lli m){
	lli ans = 1;
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

pair<lli, lli> chinese(const vector<lli>& a, const vector<lli>& m){
	lli prod = 1, p, ans = 0;
	for(lli ni : m) prod *= ni;
	for(int i = 0; i < a.size(); ++i){
		p = prod / m[i];
		ans += (a[i] % m[i]) * modularInverse(p, m[i]) % prod * p % prod;
		while(ans >= prod) ans -= prod; while(ans < 0) ans += prod;
	}
	return {ans, prod};
}

vector<lli> divsSum;
vector<vector<int>> divs;
void divisorsSieve(int n){
	divsSum.resize(n + 1, 0);
	divs.resize(n + 1);
	for(int i = 1; i <= n; ++i){
		for(int j = i; j <= n; j += i){
			divsSum[j] += i;
			divs[j].push_back(i);
		}
	}
}

vector<int> primesSieve(int n){
	vector<bool> is(n+1, true);
	vector<int> primes = {2};
	is[0] = is[1] = false;
	for(int i = 4; i <= n; i += 2) is[i] = false;
	for(int i = 3; i <= n; i += 2){
		if(is[i]){
			primes.push_back(i);
			if((long long)i*i <= n)
				for(int j = i*i; j <= n; j += 2*i)
					is[j] = false;
		}
	}
	return primes;
}

vector<int> primes;

vector<int> lowestPrimeSieve(int n){
	vector<int> lp(n+1);
	iota(lp.begin(), lp.end(), 0);
	for(int i = 4; i <= n; i += 2) lp[i] = 2;
	for(int i = 3; i*i <= n; i += 2)
		if(lp[i] == i)
			for(int j = i*i; j <= n; j += 2*i)
				lp[j] = min(lp[j], i);
	return lp;
}


vector<vector<int>> primeFactorsSieve(int n){
	vector<vector<int>> primeFactors(n+1);
	for(int p = 2; p <= n; ++p){
		if(primeFactors[p].empty())
			for(int j = p; j <= n; j += p)
				primeFactors[j].push_back(p);
	}
	return primeFactors;
}

vector<int> phiSieve(int n){
	vector<int> Phi(n+1);
	iota(Phi.begin(), Phi.end(), 0);
	for(int i = 2; i <= n; ++i)
		if(Phi[i] == i)
			for(int j = i; j <= n; j += i)
				Phi[j] -= Phi[j] / i;
	return Phi;
}

vector<vector<lli>> ncrSieve(int n){
	vector<vector<lli>> Ncr(n+1);
	Ncr[0] = {1};
	for(int i = 1; i <= n; ++i){
		Ncr[i].resize(i + 1);
		Ncr[i][0] = Ncr[i][i] = 1;
		for(int j = 1; j <= i / 2; j++)
			Ncr[i][i - j] = Ncr[i][j] = Ncr[i - 1][j - 1] + Ncr[i - 1][j];
	}
	return Ncr;
}

vector<pair<lli, int>> factorize(lli n){
	vector<pair<lli, int>> f;
	for(lli p : primes){
		if(p * p > n) break;
		int pot = 0;
		while(n % p == 0){
			pot++;
			n /= p;
		}
		if(pot) f.emplace_back(p, pot);
	}
	if(n > 1) f.emplace_back(n, 1);
	return f;
}

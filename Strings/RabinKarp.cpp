#include <iostream>

using namespace std;

vector<int> rabin_karp(string const &s, string const &t) {
    const int p = 31;
    const int m = int(1e9) + 9;
    int S = s.size(), T = t.size();

    //Precalcular potencias 
    vector<long long> p_pow(max(S, T));
    p_pow[0] = 1;
    for(int i = 1; i < (int)p_pow.size(); i++) {
        p_pow[i] = (p_pow[i-1] * p) % m;
    }
    
    //Precalcular prefijos hash T
    vector<long long> h(T + 1, 0);
    for (int i = 0; i < T; i++) {
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
    }
    
    //Calcular hash de s
    long long h_s = 0;
    for(int i = 0; i < S; i++) {
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;
    }
    
    //Rabin Karp
    vector<int> ocurrencias;
    for(int i = 0; i + S - 1 < T; i++) {
        long long cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m) {
            ocurrencias.push_back(i);
        }
    }
    return ocurrencias; 
}


int main() {

}
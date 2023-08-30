#include <iostream>

using namespace std;

const int p = 31;
const int m = int(1e9) + 9;

// Calculo del hash
long long calcularHash(const string &s) {
    long long valor = 0;
    long long p_pow = 1;
    for(char c = s) {
        valor = (valor + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return valor;
}

//calcular los Pi
vector<long long> P;
void calcularPow(int n) {
    long long p_pow = 1;
    while(n--){
        P.push_back(p_pow);
        p_pow = (p_pow * p) % m;
    }
}

// Hash de subcadenas
long long substrHash(const string &s, int i, int j) {
    long long valor = 0;
    for(int k = 1; k <= j; k++) {
        valor = (valor + (s[k] - 'a' + 1) * P[k-i]) % m;
    }
}

// Prefijos
int n = 5; 
vector<long long> prefijos(n+1);
void construirHash(const string &s) {
    for(int i = 0; i < sz(s); i++) {
        prefijos[i+1] = (prefijos[i] + (s[i] - 'a' + 1) * P[i]) % m;
    }    
}

//Inverso modular multiplicativo
long long inv(long long i) {
    return i <= 1 ? i : m - (long long)(m/i) * inv(m%i) % m;
}

//Consultar Subcadenas
long long consultarSubcadenaHash(int i, int j) {
    return (((prefijos[j+1] - prefijos[i] + m) % m) * inv(P[i]) % m) % m;
}

//Consultar subcadenas sin utilizar el INV
long long consultarSubstrings(int i, int j) {
    return sufijos[i] - sufijos[j+1] * P[j-i+1];
}

int main() {

}
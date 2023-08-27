vector<int> getPrimes(int n){
    vector<bool> is(n+1, true);
    vector<int> primes = {2}; // introducimos el 2 a mano, pues solo procesamos los primos impares por la optimización
    is[0] = is[1] = false;
    for(int i = 4; i <= n; i += 2){
        is[i] = false;
    }
    for(int i = 3; i <= n; i += 2){
        if(is[i]){
            primes.push_back(i);     // como i es primo, lo introducimos al arreglo
            if((long long)i*i <= n){ // chequeo adicional para evitar desbordar i*i
                for(int j = i*i; j <= n; j += 2*i){
                    is[j] = false;
                }
            }
        }
    }
    return primes; // ahora devolvemos el arreglo de primos
}

// precalcular solo una vez el arreglo primes con la criba antes de llamar a esta función
bool isPrime(int n){//O(√n/log(n))
    if(n == 1) return false; // El 1 sigue siendo un caso especial
    for(int p : primes){ // Ahora iteramos únicamente sobre los primos
        if((long long)p*p > n) break; // Solo nos interesan los primos p tales que p*p <= n
        if(n % p == 0){
            return false; // Encontramos un divisor primo de n que no es ni 1 ni n
        }
    }
    return true; // Si llegamos hasta este punto, n tiene que ser primo
}

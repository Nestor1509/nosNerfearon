//arreglo de primos entre 1 - n
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

//true primos entre 1 - n O(nlog(logn))
vector<bool> sieve(ll n){
    vector<bool> is(n+1, true); // arreglo de marcas inicializado en true, es decir, todos los números son "primos" al inicio
    is[0] = is[1] = false;      // excepto el 0 y el 1
    for(ll i = 4; i <= n; i += 2){
        is[i] = false; // marcamos todos los múltiplos mayores de 2 como compuestos
    }
    for(ll i = 3; i*i <= n; i += 2){ // comenzamos a iterar por los impares desde el 3
        if(is[i]){ // si el número actual es primo, marcamos todos sus múltiplos mayores
            for(ll j = i*i; j <= n; j += 2*i){ // comenzamos en i*i y solo iteramos por los impares
                is[j] = false;
            }
        }
    }
    return is;
}

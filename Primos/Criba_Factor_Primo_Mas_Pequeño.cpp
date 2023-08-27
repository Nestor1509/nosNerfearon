//criba del factor primo más pequeño
vector<int> lpSieve(int n){
    vector<int> lp(n+1);           // arreglo del factor primo más pequeño
    iota(lp.begin(), lp.end(), 0); // usamos la STL para rellenar el arreglo inicial
    for(int i = 4; i <= n; i += 2){
        lp[i] = 2; // 2 es el factor primo más pequeño de todos los números pares
    }
    for(int i = 3; i*i <= n; i += 2){ // comenzamos a iterar por los impares desde el 3
        if(lp[i] == i){ // si el número actual es primo, actualizamos todos sus múltiplos mayores
            for(int j = i*i; j <= n; j += 2*i){ // comenzamos en i*i y solo iteramos por los impares
                lp[j] = min(lp[j], i);
            }
        }
    }
    return lp;
}

//criba del factor primo más grande
vector<int> gpSieve(int n) {
    vector<int> gp(n+1);           // arreglo del factor primo más grande
    iota(gp.begin(), gp.end(), 0); // usamos la STL para rellenar el arreglo inicial
    for(int i = 2; i <= n; i++){
        if(gp[i] == i){ // si el número actual es primo, actualizamos todos sus múltiplos mayores
            for(int j = 2*i; j <= n; j += i){
                gp[j] = i; // al siempre actualizar los múltiplos, garantizamos siempre guardar el factor primo más grande
            }
        }
    }
    return gp;
}

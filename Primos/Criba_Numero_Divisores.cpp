//Numero de divisores de 1 - n
vector<int> divsSieve(int n){//O(n√n)
    vector<int> divs(n+1); // incializamos el arreglo en ceros
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j += i){ // iteramos por todos los múltiplos de i
            divs[j]++;
        }
    }
    return divs;
}

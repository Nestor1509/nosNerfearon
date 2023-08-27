Dado un string s retorna un vector pf donde pf[i] es el largo del prefijo propio mas largo que tambien es sufijo de s[0] hasta s[i].
/// O(n)
vector<int> prefix_function(string &s) {
    int n = s.size();
    vector<int> pf(n);
    pf[0] = 0;
    for (int i = 1, j = 0; i < n; i++) {
        while (j && s[i] != s[j]) j = pf[j-1];
        if (s[i] == s[j]) j++;
        pf[i] = j;
    }
    return pf;
}
Cuenta las ocurrencias del string p en el string s. Agregar Prefix Function.
/// O(n+m)
int kmp(string &s, string &p) {
    int n = s.size(), m = p.size(), cnt = 0;
    vector<int> pf = prefix_function(p);
    for(int i = 0, j = 0; i < n; i++) {
        while(j && s[i] != p[j]) j = pf[j-1];
        if(s[i] == p[j]) j++;
        if(j == m) {
            cnt++;
            j = pf[j-1];
        }
    }
    return cnt;
}

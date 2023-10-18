const int mx = (int)(2*1e5 + 7);
vector <int> g[mx];
bool vis[mx];
map <int, int> mp;

void dfs(int x, int n){
    vis[x] = 1; 
    for(auto &i: g[x]){
        mp[i]++;
        if(!vis[i]){
            dfs(i, n);
        }
    }
}

int main() {
    fast
    
    int n, m, a, b;
    cin>>n>>m;
    
    forn (i, m){
        cin>>a>>b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    
    int c = 0;
    forn (i, n){
        if (!vis[i]){
            mp.clear();
            dfs(i, i);
            bool b = 1;
            for (auto iter = mp.begin(); iter != mp.end(); iter++) {
                if (iter -> second != 2){
                    b = 0;
                    break;
                }
            }
            if (b && sz(g[i]) > 0) c++;
        }
    }
    cout<<c<<endl;
    return 0;
}

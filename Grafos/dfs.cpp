void dfs(int x){
    vis[x] = 1; 
    for(auto &i : g[x]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

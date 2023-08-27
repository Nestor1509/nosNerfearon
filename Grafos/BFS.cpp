//BFS
vector <int> g[100];
bool vis[100];
void bfs(int x){
    queue <int> c; c.push(x);
    while(!c.empty()){
        int s = c.front(); vis[s] = 1; c.pop();
        for(auto &it: g[s]){
            if(!vis[it]) c.push(it);
        }
    }
}

#include <bits/stdc++.h> //
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rfor(i, n) for (int i = n; i > 0; i--)
#define form(i, n, m) for (int i = n; i <= m; i++)
#define forn(i, n) for (int i = 0; i < n; i++)
#define ms(x, n) memset(x, n, sizeof(x))
#define vpi vector<pair<int, int>>
#define all(x) x.begin(), x.end()
#define ii pair<int, int>
#define vi vector<int>
#define sz(x) x.size()
// #define int long long
#define ll long long
#define ld long double
#define pb push_back
#define ss second
#define endl '\n'
#define ff first
using namespace std;
//" \n"[i == n - 1]
// nosNerfearon();
const int mx = 1e4 + 5;
struct edge {
  int v, l, vel; 
  ld w;

  bool operator < (const edge &x) const {
    return x.w < w;
  }
};
vector<edge> g[mx];

void limpiar(int n){
  forn(i, n) g[i].clear();
}
ld f(edge &a, ld x){
  return (ld) a.l / (a.vel + x);
}
void dijkstra(edge v, ld x, vector<ld> &dist) {
  priority_queue<edge> pq;
  pq.push(v);
  dist[v.v] = 0;
  while (sz(pq)) {
    v = pq.top();
    pq.pop();
    if (v.w > dist[v.v]) continue;
    for (edge &u : g[v.v]) {
      u.w = f(u, x);
      if (dist[u.v] > dist[v.v] + u.w) {
        dist[u.v] = dist[v.v] + u.w;
        pq.push({u.v, u.l, u.vel, dist[u.v]});
      }
    }
  }
}
signed main() {
    fast
    cout << fixed << setprecision(10);
    int n, m, t; cin >> n >> m >> t;
    forn(i, m){
      int a, b, l, v; cin >> a >> b >> l >> v; a--; b--;
      g[a].pb({b, l, v, 0});
      g[b].pb({a, l, v, 0});
    }
    ld l = 0, r = 1e9;
    vector<ld> dist(n);
    forn(i, 50){
      fill(all(dist), LLONG_MAX);
      ld mid = (l + r) / 2;
      dijkstra({0, 0, 0, 0}, mid, dist);
      if(dist[n - 1] <= t) r = mid;
      else l = mid;
    }
    fill(all(dist), LLONG_MAX);
    dijkstra({0, 0, 0, 0}, l, dist);
    cout << (dist[n - 1] <= t? l: r) << endl;
    cout << flush;
}

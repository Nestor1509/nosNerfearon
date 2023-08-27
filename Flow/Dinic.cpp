#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int bfs(vector<vector<int>>& grafo, vector<vector<int>>& residual, vector<int>& padre, int fuente, int sumidero) {
    int n = grafo.size();
    vector<bool> visitado(n, false);
    queue<pii> cola;
    cola.push(make_pair(fuente, INT_MAX));
    visitado[fuente] = true;
    padre[fuente] = -1;

    while (!cola.empty()) {
        int u = cola.front().first;
        int flujo = cola.front().second;
        cola.pop();

        for (int v = 0; v < n; v++) {
            if (!visitado[v] && residual[u][v] > 0) {
                int nuevo_flujo = min(flujo, residual[u][v]);
                padre[v] = u;
                visitado[v] = true;
                cola.push(make_pair(v, nuevo_flujo));

                if (v == sumidero) {
                    return nuevo_flujo;
                }
            }
        }
    }
    return 0;
}

int flujoMaximo(vector<vector<int>>& grafo, int fuente, int sumidero) {
    int n = grafo.size();
    vector<vector<int>> residual(n, vector<int>(n, 0));
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            residual[u][v] = grafo[u][v];
        }
    }

    vector<int> padre(n, -1);
    int flujo_maximo = 0;
    int nuevo_flujo;

    while ((nuevo_flujo = bfs(grafo, residual, padre, fuente, sumidero)) > 0) {
        flujo_maximo += nuevo_flujo;
        int v = sumidero;
        while (v != fuente) {
            int u = padre[v];
            residual[u][v] -= nuevo_flujo;
            residual[v][u] += nuevo_flujo;
            v = u;
        }
    }

    return flujo_maximo;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grafo(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        grafo[u - 1][v - 1] += c;
        grafo[v - 1][u - 1] += c;
    }

    int fuente = 0;
    int sumidero = n - 1;
    int flujo_maximo = flujoMaximo(grafo, fuente, sumidero);

    cout << flujo_maximo << endl;

    return 0;
}

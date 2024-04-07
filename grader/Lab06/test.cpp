#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAXN = 100; // maximum number of vertices
int graph[MAXN][MAXN]; // adjacency matrix representation of graph
int dist[MAXN]; // distance from source to each vertex
bool visited[MAXN]; // visited flag for each vertex

int prim(int start, int n) {
    fill(dist, dist+n, INT_MAX);
    fill(visited, visited+n, false);
    dist[start] = 0;

    int mst_cost = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        visited[u] = true;
        mst_cost += dist[u];

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != -1 && graph[u][v] < dist[v]) {
                dist[v] = graph[u][v];
            }
        }
    }

    return mst_cost;
}

int main() {
    int n, m; // n = number of vertices, m = number of edges
    cin >> n >> m;

    // initialize graph with -1 (i.e., no edge)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = -1;
        }
    }

    // read in edges
    for (int i = 0; i < m; i++) {
        int u, v, w; // edge from u to v with weight w
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w; // undirected graph
    }

    int mst_cost = prim(0, n);
    cout << "Minimum spanning tree cost: " << mst_cost << endl;

    return 0;
}

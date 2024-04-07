#include <iostream>
#include <sstream>
using namespace std;

int NMAX = 100;

int prim(int graph[100][100], bool *visited, int *best_dist, int n, int start) {
    int MST_cost;
    best_dist[start] = 0;

    for (int i = 0; i < n; i++) {
        int temp = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (best_dist[j] < best_dist[temp])) { // ! visited : unvisited
                temp = j;
            } 
        }

        visited[temp] = true;
        MST_cost += best_dist[temp];

        for (int j = 0; j < n; j++) {
            if (!visited[j] && graph[temp][j] < best_dist[j]) {
                best_dist[j] = graph[temp][j];
            }
        }
    }

    cout << MST_cost;

    return MST_cost;
}

int main()
{
    // n : village's amount, v : path's amount, starting village, cost of each path
    int n, v, start, cost;
    // path input handle
    int origin, dest;

    cin >> n;
    cin >> v;

    int graph[n + 1][n + 1], best_dist[n];
    bool visited[n];
    int **ptr = new int*[n];

    cin >> start;

    if (start > n) {
        cout << "What did you expect?";
        return 0;
    }

    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            graph[i][j] = graph[j][i] = NMAX;
        }
    }

    for (int i = 0; i < n; i++) {
        best_dist[i] = 9;
        visited[i] = false;
    }

    for (int i = 0; i < v; i++) {
        cin >> origin >> dest >> cost;
        graph[origin][dest] = graph[dest][origin] = cost;    
    }

    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    // passing 2d array handle
    for (int i = 0; i < n + 1; ++i) {
        ptr[i] = graph[i];
    }

    prim(graph, visited, best_dist, n + 1, start);

    return 0;
}
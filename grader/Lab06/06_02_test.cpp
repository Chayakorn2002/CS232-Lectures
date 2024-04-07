#include <iostream>
#include <sstream>
using namespace std;

int NMAX = 9;
int graph[100][100];
int visited[100];
int best_dist[100];

int prim(int n, int start) {
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

    int best_dist[n];
    bool visited[n];

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

    prim(n + 1, start);

    return 0;
}
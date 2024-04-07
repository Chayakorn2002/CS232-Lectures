#include <iostream>
#include <map>
#include <limits>
using namespace std;

class Graph
{
private:
    int N;    // No. of nodes
    map<char, map<char, int>> graph;   // Adjacency map
    void swap(char &x, char &y);    // little swap function
    void printMST(map<char, map<char, int>> prim);      // printing function

public:
    Graph();   // Constructor
    void addEdge(char v, char w, int weight);   // to add an edge to graph
    void primMST(char start);    // returns minimum cost of MST
};

Graph::Graph()
{
    N = 1;
}

void Graph::addEdge(char v, char u, int distance)
{
    // If there's a new node
    if (graph.count(v) == 0 || graph.count(u) == 0)
        N++; 

    // Adding edge
    graph[v][u] = distance;
    graph[u][v] = distance;
}

void Graph::swap(char &x, char &y)
{
    char temp = x;
    x = y;
    y = temp;
}

void Graph::printMST(map<char, map<char, int>> prim)
{
    // Iterators
    map<char, map<char, int>>::iterator outer;
    map<char, int>::iterator inner;

    for (outer = prim.begin(); outer != prim.end(); outer++)
        for (inner = outer->second.begin(); inner != outer->second.end(); inner++)
            cout << outer->first << " " << inner->second << " " << inner->first << endl;

    // Note: traversing 2d map is so complicated
}

void Graph::primMST(char start)
{
    // Prim's MST
    map<char, map<char, int>> prim;   

    // initialize visited
    map<char, bool> visited;    
    for (map<char, map<char, int>>::iterator pair = graph.begin(); pair != graph.end(); pair++)
        visited[pair->first] = false;

    // visit a starting node (it can be any node but this one works so..)
    visited[start] = true;

    char x = '\0', y = '\0';

    // Iterators
    map<char, map<char, int>>::iterator outer;
    map<char, int>::iterator inner;

    // traverse through the map and search for min edge for each node
    for (int count = 0; count < N - 1; count++) 
    {
        int min = numeric_limits<int>::max(); // highest number
        for (outer = graph.begin(); outer != graph.end(); outer++) 
        {
            if (visited[outer->first]) 
            {
                for (inner = outer->second.begin(); inner != outer->second.end(); inner++) {
                    // not in visited
                    if (!visited[inner->first] && inner->second < min) {  
                        min = inner->second;
                        x = outer->first;
                        y = inner->first;
                    }
                }
            }
        }
        visited[y] = true;

        // if x is more than y, we swap them
        if (x > y)
            swap(x, y);

        prim[x][y] = graph[x][y];     
    }
    printMST(prim);
}

int main()
{
    int n, i, dis;
    char start, x, y;
    Graph g;

    cin >> n >> start;

    for (i = 0; i < n; i++) {
        cin >> x >> dis >> y;
        g.addEdge(x, y, dis);
    }

    g.primMST(start);

}

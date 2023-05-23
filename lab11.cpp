#include <iostream>
#include <climits>

#define V 6
using namespace std;

int Key(int key[], bool mstSet[]) {
    int Val = INT_MAX, Index;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < Val) {
            Val = key[v];
            Index = v;
        }
    }

    return Index;
}

void print_MST(int start[], int graph[V][V]) {
    cout << "Edge   Weight"<<endl;
    for (int j = 1; j < V; j++) {
        cout << start[j] << " - " << j << "    " << graph[j][start[j]] << endl;
    }
}

void MST_prim(int graph[V][V]) {
    int start[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    start[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = Key(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                start[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    print_MST(start, graph);
}

int main() {
    int graph[V][V] = { { 0, 3, 0, 0, 0, 1 },
                        { 3, 0, 2, 1, 10, 0 },
                        { 0, 2, 0, 3, 0, 5 },
                        { 0, 1, 3, 0, 5, 0 },
                        { 0, 10, 0, 5, 0, 4 },
                        { 1, 0, 5, 0, 4, 0 } };

    MST_prim(graph);

    return 0;
}

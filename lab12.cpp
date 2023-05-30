#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <stack>

using namespace std;

void dijkstra(vector<vector<int>>& graph, int source, vector<int>& distances, vector<int>& previous) {
    int num_cities = graph.size();
    distances.resize(num_cities, INT_MAX);
    previous.resize(num_cities, -1);
    distances[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int currentCity = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > distances[currentCity])
            continue;

        for (int neighborCity = 0; neighborCity < num_cities; neighborCity++) {
            int neighborDist = graph[currentCity][neighborCity];
            if (neighborDist > 0) {
                int newDist = distances[currentCity] + neighborDist;
                if (newDist < distances[neighborCity]) {
                    distances[neighborCity] = newDist;
                    previous[neighborCity] = currentCity;
                    pq.push({newDist, neighborCity});
                }
            }
        }
    }
}

void printgraph(vector<int>& previous, int city) {
    stack<int> path;
    while (city != -1) {
        path.push(city);
        city = previous[city];
    }

    cout << "Path taken: ";
    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
    cout << endl;
}

int main() {
    vector<vector<int>> graph = {{ 0, 10, 0, 0, 15, 5 }, { 10, 0, 10, 30, 0, 0 }, { 0, 10, 0, 12, 5, 0 }, { 0, 30, 12, 0, 0, 20 }, { 15, 0, 5, 0, 0, 0 }, { 5, 0, 0, 20, 0, 0 }};

    int sourceCity = 0;

    vector<int> distances;
    vector<int> previous;
    dijkstra(graph, sourceCity, distances, previous);

    for (int i = 0; i < distances.size(); i++) {
        cout << "Time taken from city " << sourceCity << " to city " << i << " : " << distances[i] << endl;
        printgraph(previous, i);
    }

    return 0;
}

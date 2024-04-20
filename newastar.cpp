#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <cmath>
#include <functional>
using namespace std;

struct Node {
    int index;
    int g_cost;
    int h_cost;
    int f_cost;
    int parent;
    Node(int i, int g, int h, int p) : index(i), g_cost(g), h_cost(h), f_cost(g + h), parent(p) {}
};

// Custom reverse function
void reverse(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n / 2; ++i) {
        int temp = v[i];
        v[i] = v[n - i - 1];
        v[n - i - 1] = temp;
    }
}

int AStar(vector<vector<int>>& graph, vector<int>& heuristic, int start, int goal, vector<int>& path) {
    int n = graph.size();

    priority_queue<Node, vector<Node>, function<bool(const Node&, const Node&)>> openList(
        [](const Node& a, const Node& b) {
            return a.f_cost > b.f_cost;
        }
    );

    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    openList.push(Node(start, 0, heuristic[start], -1));

    while (!openList.empty()) {
        Node current = openList.top();
        openList.pop();

        if (current.index == goal) {
            int node = current.index;
            while (node != -1) {
                path.push_back(node);
                node = parent[node];
            }
            reverse(path); // Using the custom reverse function
            return current.g_cost;
        }

        visited[current.index] = true;

        for (int neighbor = 0; neighbor < n; ++neighbor) {
            if (graph[current.index][neighbor] != 0 && !visited[neighbor]) {
                int g_cost = current.g_cost + graph[current.index][neighbor];
                int h_cost = heuristic[neighbor];
                int f_cost = g_cost + h_cost;

                openList.push(Node(neighbor, g_cost, h_cost, current.index));
                parent[neighbor] = current.index;
            }
        }
    }

    return -1; // No path found
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    vector<int> heuristic(n, 0);

    cout << "Enter the heuristic values for each node:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> heuristic[i];
    }

    int start, goal;
    cout << "Enter the start node: ";
    cin >> start;
    cout << "Enter the goal node: ";
    cin >> goal;

    vector<int> path;
    int shortestPathCost = AStar(graph, heuristic, start, goal, path);

    if (shortestPathCost == -1) {
        cout << "No path found from node " << start << " to node " << goal << endl;
    } else {
        cout << "Shortest path cost from node " << start << " to node " << goal << " is: " << shortestPathCost << endl;
        cout << "Shortest path: ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}

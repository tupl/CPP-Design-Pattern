#include <algorithm>
#include <unordered_set>

class Solution {
public:
    void visit(vector<unordered_set<int>>& adjList, vector<bool>& visited, int i) {
        unordered_set<int> adj = adjList[i];
        visited[i] = true;
        for(auto it = adj.begin(); it != adj.end(); ++it) {
            int vertex = *it;
            if (!visited[vertex]) {
                visit(adjList, visited, vertex);
            }
        }
    }

    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int> > ls(n);
        vector<bool> visited(n, false);
        for(int i = 0; i < edges.size(); ++i) {
            int fr = edges[i].first;
            int to = edges[i].second;
            ls[fr].insert(to);
            ls[to].insert(fr);
        }
        int k = 0;
        for(int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++k;
                visit(ls, visited, i);
            }
        }
        return k;
    }
};
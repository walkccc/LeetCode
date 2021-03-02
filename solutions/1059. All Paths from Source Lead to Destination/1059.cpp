enum State { INIT, VISITING, VISITED };

class Solution {
 public:
  bool leadsToDestination(int n, vector<vector<int>>& edges, int source,
                          int destination) {
    vector<vector<int>> graph(n);
    vector<State> state(n);

    for (const auto& edge : edges)
      graph[edge[0]].push_back(edge[1]);

    return acyclic(graph, source, destination, state);
  }

 private:
  bool acyclic(const vector<vector<int>>& graph, int node, int dest,
               vector<State>& state) {
    if (graph[node].empty())
      return node == dest;
    if (state[node] == VISITING)
      return false;
    if (state[node] == VISITED)
      return true;

    state[node] = VISITING;
    for (const int child : graph[node])
      if (!acyclic(graph, child, dest, state))
        return false;
    state[node] = VISITED;

    return true;
  }
};

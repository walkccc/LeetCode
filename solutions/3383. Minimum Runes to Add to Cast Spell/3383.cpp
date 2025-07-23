class Solution {
 public:
  int minRunesToAdd(int n, vector<int>& crystals, vector<int>& flowFrom,
                    vector<int>& flowTo) {
    vector<vector<int>> graph(n);
    vector<vector<int>> reversedGraph(n);

    for (int i = 0; i < flowFrom.size(); ++i) {
      const int u = flowFrom[i];
      const int v = flowTo[i];
      graph[u].push_back(v);
      reversedGraph[v].push_back(u);
    }

    // Identify Strongly Connected Components (SCC) using Kosaraju's Algorithm
    vector<bool> seen(n);
    vector<int> orderStack;
    vector<int> componentIds(n, -1);
    int componentCount = 0;

    for (int i = 0; i < n; ++i)
      if (!seen[i])
        kosaraju(graph, i, seen, orderStack);

    for (int i = n - 1; i >= 0; --i) {
      const int u = orderStack[i];
      if (componentIds[u] == -1)
        identifySCC(reversedGraph, u, componentIds, componentCount++);
    }

    // Track crystal-containing components and inter-component edges.
    vector<bool> hasCrystal(componentCount);
    vector<bool> hasInterComponentEdge(componentCount);

    for (const int u : crystals)
      hasCrystal[componentIds[u]] = true;

    for (int i = 0; i < flowFrom.size(); ++i) {
      const int id1 = componentIds[flowFrom[i]];
      const int id2 = componentIds[flowTo[i]];
      if (id1 != id2)  // Edge is inter-component.
        hasInterComponentEdge[id2] = true;
    }

    // Count components requiring additional runes.
    int ans = 0;

    for (int i = 0; i < componentCount; ++i)
      if (!hasCrystal[i] && !hasInterComponentEdge[i])
        ++ans;

    return ans;
  }

 private:
  // Creates a topological order stack using Kosaraju's Algorithm.
  void kosaraju(const vector<vector<int>>& graph, int u, vector<bool>& seen,
                vector<int>& orderStack) {
    seen[u] = true;
    for (const int v : graph[u])
      if (!seen[v])
        kosaraju(graph, v, seen, orderStack);
    orderStack.push_back(u);
  }

  // Assigns component IDs during SCC identification in the second DFS.
  void identifySCC(const vector<vector<int>>& reversedGraph, int u,
                   vector<int>& componentIds, int componentId) {
    if (componentIds[u] != -1)
      return;
    componentIds[u] = componentId;
    for (const int v : reversedGraph[u])
      if (componentIds[v] < 0)
        identifySCC(reversedGraph, v, componentIds, componentId);
  }
};

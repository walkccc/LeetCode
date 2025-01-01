class Solution {
 public:
  vector<int> countVisitedNodes(vector<int>& edges) {
    const int n = edges.size();
    vector<int> ans(n);
    vector<int> inDegrees(n);
    vector<bool> seen(n);
    queue<int> q;
    stack<int> stack;

    for (const int v : edges)
      ++inDegrees[v];

    // Perform topological sorting.
    for (int i = 0; i < n; ++i)
      if (inDegrees[i] == 0)
        q.push(i);

    // Push non-cyclic nodes to stack.
    while (!q.empty()) {
      const int u = q.front();
      q.pop();
      if (--inDegrees[edges[u]] == 0)
        q.push(edges[u]);
      stack.push(u);
      seen[u] = true;
    }

    // Fill the length of cyclic nodes.
    for (int i = 0; i < n; ++i)
      if (!seen[i])
        fillCycle(edges, i, seen, ans);

    // Fill the length of non-cyclic nodes.
    while (!stack.empty()) {
      const int u = stack.top();
      stack.pop();
      ans[u] = ans[edges[u]] + 1;
    }

    return ans;
  }

 private:
  void fillCycle(const vector<int>& edges, int start, vector<bool>& seen,
                 vector<int>& ans) {
    int cycleLength = 0;
    for (int u = start; !seen[u]; u = edges[u]) {
      ++cycleLength;
      seen[u] = true;
    }
    ans[start] = cycleLength;
    for (int u = edges[start]; u != start; u = edges[u])
      ans[u] = cycleLength;
  }
};

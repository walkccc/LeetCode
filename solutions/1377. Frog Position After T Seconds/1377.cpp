class Solution {
 public:
  double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
    vector<double> prob(n + 1);
    vector<bool> visited(n + 1);
    queue<int> queue{{1}};
    vector<vector<int>> graph(n + 1);

    prob[1] = 1.0;
    visited[1] = true;

    for (vector<int>& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    for (int i = 0; i < t; ++i)
      for (int j = queue.size(); j > 0; --j) {
        int curr = queue.front();
        queue.pop();
        int children =
            count_if(begin(graph[curr]), end(graph[curr]),
                     [&visited](int child) { return !visited[child]; });
        for (int child : graph[curr])
          if (!visited[child]) {
            visited[child] = true;
            prob[child] = prob[curr] / children;
            queue.push(child);
          }
        if (children > 0) prob[curr] = 0.0;
      }

    return prob[target];
  }
};
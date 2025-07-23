class Solution {
 public:
  int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
    int ans = 0;
    int minCount = graph.size();

    ranges::sort(initial);

    for (const int i : initial) {
      const int count = bfs(graph, i, initial);
      if (count < minCount) {
        minCount = count;
        ans = i;
      }
    }

    return ans;
  }

 private:
  int bfs(const vector<vector<int>>& graph, int removed, vector<int>& initial) {
    queue<int> q;
    vector<bool> seen(graph.size());
    seen[removed] = true;

    int count = 0;

    for (const int i : initial)
      if (i != removed) {
        q.push(i);
        seen[i] = true;
      }

    while (!q.empty()) {
      const int u = q.front();
      q.pop();
      ++count;
      for (int i = 0; i < graph.size(); ++i) {
        if (seen[i])
          continue;
        if (i != u && graph[i][u]) {
          q.push(i);
          seen[i] = true;
        }
      }
    }

    return count;
  }
};

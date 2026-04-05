class Solution {
 public:
  long long maxScore(int n, vector<vector<int>>& edges) {
    long ans = 0;
    vector<vector<int>> graph(n);
    vector<int> cycleSizes;  // components where all nodes have degree 2
    vector<int> pathSizes;   // components that are not cycleSizes
    vector<bool> seen(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
      if (seen[i])
        continue;
      const vector<int> component = getComponent(graph, i, seen);
      const bool allDegree2 = ranges::all_of(
          component, [&graph](int u) { return graph[u].size() == 2; });
      if (allDegree2)
        cycleSizes.push_back(component.size());
      else if (component.size() > 1)
        pathSizes.push_back(component.size());
    }

    for (const int cycleSize : cycleSizes) {
      ans += calculateScore(n - cycleSize + 1, n, /*isCycle=*/true);
      n -= cycleSize;
    }

    ranges::sort(pathSizes, greater<>());

    for (const int pathSize : pathSizes) {
      ans += calculateScore(n - pathSize + 1, n, /*isCycle=*/false);
      n -= pathSize;
    }

    return ans;
  }

 private:
  vector<int> getComponent(const vector<vector<int>>& graph, int start,
                           vector<bool>& seen) {
    vector<int> component = {start};
    seen[start] = true;
    for (int i = 0; i < component.size(); ++i) {
      const int u = component[i];
      for (const int v : graph[u]) {
        if (seen[v])
          continue;
        component.push_back(v);
        seen[v] = true;
      }
    }
    return component;
  }

  long calculateScore(int left, int right, bool isCycle) {
    deque<long> window = {right, right};
    long score = 0;
    for (int value = right - 1; value >= left; --value) {
      const long windowValue = window.front();
      window.pop_front();
      score += windowValue * value;
      window.push_back(value);
    }
    return score + window[0] * window[1] * isCycle;
  }
};

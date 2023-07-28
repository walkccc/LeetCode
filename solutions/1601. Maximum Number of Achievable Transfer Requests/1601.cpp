class Solution {
 public:
  int maximumRequests(int n, vector<vector<int>>& requests) {
    int ans = 0;
    vector<int> degree(n);  // degree[i] := degree of building i

    function<void(int, int)> dfs = [&](int i, int processedReqs) {
      if (i == requests.size()) {
        if (all_of(degree.begin(), degree.end(), [](int d) { return d == 0; }))
          ans = max(ans, processedReqs);
        return;
      }

      // Skip requests[i]
      dfs(i + 1, processedReqs);

      // Process requests[i]
      --degree[requests[i][0]];
      ++degree[requests[i][1]];
      dfs(i + 1, processedReqs + 1);
      --degree[requests[i][1]];
      ++degree[requests[i][0]];
    };

    dfs(0, 0);

    return ans;
  }
};

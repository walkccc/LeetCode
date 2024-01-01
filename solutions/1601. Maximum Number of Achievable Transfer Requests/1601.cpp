class Solution {
 public:
  int maximumRequests(int n, vector<vector<int>>& requests) {
    int ans = 0;
    vector<int> degrees(n);  // degrees[i] := degrees of the i-th building

    function<void(int, int)> dfs = [&](int i, int processedReqs) {
      if (i == requests.size()) {
        if (ranges::all_of(degrees, [](int d) { return d == 0; }))
          ans = max(ans, processedReqs);
        return;
      }

      // Skip the requests[i].
      dfs(i + 1, processedReqs);

      // Process the requests[i].
      --degrees[requests[i][0]];
      ++degrees[requests[i][1]];
      dfs(i + 1, processedReqs + 1);
      --degrees[requests[i][1]];
      ++degrees[requests[i][0]];
    };

    dfs(0, 0);

    return ans;
  }
};

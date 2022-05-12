class Solution {
 public:
  vector<int> countPairs(int n, vector<vector<int>>& edges,
                         vector<int>& queries) {
    vector<int> ans(queries.size());

    // count[i] := # of edges of node i
    vector<int> count(n + 1);

    // shared[i][j] := # of edges incident to i or j, where i < j
    vector<unordered_map<int, int>> shared(n + 1);

    for (const auto& e : edges) {
      const int u = e[0];
      const int v = e[1];
      ++count[u];
      ++count[v];
      ++shared[min(u, v)][max(u, v)];
    }

    vector<int> sortedCount(count);
    sort(begin(sortedCount), end(sortedCount));

    int k = 0;
    for (const int q : queries) {
      for (int i = 1, j = n; i < j;)
        if (sortedCount[i] + sortedCount[j] > q)
          // sortedCount[i] + sortedCount[j] > q
          // sortedCount[i + 1] + sortedCount[j] > q
          // ...
          // sortedCount[j - 1] + sortedCount[j] > q
          // so, there are (j - 1) - i + 1 = j - i pairs > q
          ans[k] += (j--) - i;
        else
          ++i;
      for (int i = 1; i <= n; ++i)
        for (const auto& [j, sh] : shared[i])
          if (count[i] + count[j] > q && count[i] + count[j] - sh <= q)
            --ans[k];
      ++k;
    }

    return ans;
  }
};

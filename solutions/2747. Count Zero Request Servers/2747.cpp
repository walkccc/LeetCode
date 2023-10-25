class Solution {
 public:
  vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                           vector<int>& queries) {
    vector<int> ans(queries.size());
    vector<int> count(n + 1);
    vector<pair<int, int>> queryAndIndexes;

    for (int i = 0; i < queries.size(); ++i)
      queryAndIndexes.emplace_back(queries[i], i);

    sort(
        logs.begin(), logs.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
    ranges::sort(queryAndIndexes);

    int i = 0;
    int j = 0;
    int servers = 0;

    // For each query, we care about logs[i..j].
    for (const auto& [query, index] : queryAndIndexes) {
      for (; j < logs.size() && logs[j][1] <= query; ++j)
        if (++count[logs[j][0]] == 1)
          ++servers;
      for (; i < logs.size() && logs[i][1] < query - x; ++i)
        if (--count[logs[i][0]] == 0)
          --servers;
      ans[index] = n - servers;
    }

    return ans;
  }
};

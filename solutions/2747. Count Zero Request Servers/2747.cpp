struct IndexedQuery {
  int queryIndex;
  int query;
};

class Solution {
 public:
  vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                           vector<int>& queries) {
    vector<int> ans(queries.size());
    vector<int> count(n + 1);

    ranges::sort(logs, [](const vector<int>& a, const vector<int>& b) {
      return a[1] < b[1];
    });

    int i = 0;
    int j = 0;
    int servers = 0;

    // For each query, we care about logs[i..j].
    for (const auto& [queryIndex, query] : getIndexedQueries(queries)) {
      for (; j < logs.size() && logs[j][1] <= query; ++j)
        if (++count[logs[j][0]] == 1)
          ++servers;
      for (; i < logs.size() && logs[i][1] < query - x; ++i)
        if (--count[logs[i][0]] == 0)
          --servers;
      ans[queryIndex] = n - servers;
    }

    return ans;
  }

 private:
  vector<IndexedQuery> getIndexedQueries(const vector<int>& queries) {
    vector<IndexedQuery> indexedQueries;
    for (int i = 0; i < queries.size(); ++i)
      indexedQueries.push_back({i, queries[i]});
    ranges::sort(indexedQueries,
                 [](const IndexedQuery& a, const IndexedQuery& b) {
      return a.query < b.query;
    });
    return indexedQueries;
  }
};

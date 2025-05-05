class Solution {
 public:
  vector<int> queryConversions(vector<vector<int>>& conversions,
                               vector<vector<int>>& queries) {
    const vector<int> units = baseUnitConversions(conversions);
    vector<int> ans;

    for (const vector<int>& query : queries) {
      const int u = query[0];
      const int v = query[1];
      // By Fermat's little theorem.
      ans.push_back(units[v] * modPow(units[u], kMod - 2) % kMod);
    }

    return ans;
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  // Same as 3528. Unit Conversion I
  vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
    const int n = conversions.size() + 1;
    vector<int> res(n);
    res[0] = 1;
    queue<int> q{{0}};
    vector<vector<pair<int, int>>> graph(n);

    for (const vector<int>& conversion : conversions) {
      const int u = conversion[0];
      const int v = conversion[1];
      const int factor = conversion[2];
      graph[u].emplace_back(v, factor);
    }

    while (!q.empty()) {
      const int u = q.front();
      q.pop();
      for (const auto& [v, factor] : graph[u]) {
        res[v] = (static_cast<long>(res[u]) * factor) % kMod;
        q.push(v);
      }
    }

    return res;
  }

  long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x % kMod, (n - 1)) % kMod;
    return modPow(x * x % kMod, (n / 2)) % kMod;
  }
};

struct Pair {
  int x;
  int y;
};

struct IndexedQuery {
  int queryIndex;
  int minX;
  int minY;
};

class Solution {
 public:
  vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2,
                                vector<vector<int>>& queries) {
    const vector<Pair> pairs = getPairs(nums1, nums2);
    vector<int> ans(queries.size());
    vector<pair<int, int>> stack;  // [(y, x + y)]

    int pairsIndex = 0;
    for (const auto& [queryIndex, minX, minY] : getIndexedQueries(queries)) {
      while (pairsIndex < pairs.size() && pairs[pairsIndex].x >= minX) {
        const auto [x, y] = pairs[pairsIndex++];
        // x + y is a better candidate. Given that x is decreasing, the
        // condition "x + y >= stack.back().second" suggests that y is
        // relatively larger, thereby making it a better candidate.
        while (!stack.empty() && x + y >= stack.back().second)
          stack.pop_back();
        if (stack.empty() || y > stack.back().first)
          stack.emplace_back(y, x + y);
      }
      const auto it = ranges::lower_bound(stack, pair<int, int>{minY, INT_MIN});
      ans[queryIndex] = it == stack.end() ? -1 : it->second;
    }

    return ans;
  }

 private:
  vector<Pair> getPairs(const vector<int>& nums1, const vector<int>& nums2) {
    vector<Pair> pairs;
    for (int i = 0; i < nums1.size(); ++i)
      pairs.push_back({nums1[i], nums2[i]});
    ranges::sort(pairs, [](const Pair& a, const Pair& b) { return a.x > b.x; });
    return pairs;
  }

  vector<IndexedQuery> getIndexedQueries(const vector<vector<int>>& queries) {
    vector<IndexedQuery> indexedQueries;
    for (int i = 0; i < queries.size(); ++i)
      indexedQueries.push_back({i, queries[i][0], queries[i][1]});
    ranges::sort(indexedQueries,
                 [](const IndexedQuery& a, const IndexedQuery& b) {
      return a.minX > b.minX;
    });
    return indexedQueries;
  }
};

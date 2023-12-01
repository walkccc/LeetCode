struct Pair {
  int x;
  int y;
};

struct IndexAndQuery {
  int i;     // the index in `queries`
  int minX;  // queries[index] := (minX, minY)
  int minY;
};

class Solution {
 public:
  vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2,
                                vector<vector<int>>& queries) {
    const vector<Pair> pairs = getPairs(nums1, nums2);
    const vector<IndexAndQuery> indexAndQueries = getIndexAndQueries(queries);
    vector<int> ans(queries.size());
    vector<pair<int, int>> stack;  // [(y, x + y)]

    int pairsIndex = 0;
    for (const auto& [i, minX, minY] : indexAndQueries) {
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
      ans[i] = it == stack.end() ? -1 : it->second;
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

  vector<IndexAndQuery> getIndexAndQueries(const vector<vector<int>>& queries) {
    vector<IndexAndQuery> indexAndQueries;
    for (int i = 0; i < queries.size(); ++i)
      indexAndQueries.push_back(
          IndexAndQuery{.i = i, .minX = queries[i][0], .minY = queries[i][1]});
    ranges::sort(indexAndQueries,
                 [](const IndexAndQuery& a, const IndexAndQuery& b) {
      return a.minX > b.minX;
    });
    return indexAndQueries;
  }
};

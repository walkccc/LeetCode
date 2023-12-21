struct IndexedQuery {
  int queryIndex;
  int query;
};

struct T {
  int i;
  int j;
  int val;  // grid[i][j]
  T(int i, int j, int val) : i(i), j(j), val(val) {}
};

class Solution {
 public:
  vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
    const int m = grid.size();
    const int n = grid[0].size();
    const vector<int> dirs{0, 1, 0, -1, 0};
    vector<int> ans(queries.size());
    auto compare = [](const T& a, const T& b) { return a.val > b.val; };
    priority_queue<T, vector<T>, decltype(compare)> minHeap(compare);
    vector<vector<bool>> seen(m, vector<bool>(n));

    minHeap.emplace(0, 0, grid[0][0]);
    seen[0][0] = true;
    int accumulate = 0;

    for (const auto& [queryIndex, query] : getIndexedQueries(queries)) {
      while (!minHeap.empty()) {
        const auto [i, j, val] = minHeap.top();
        minHeap.pop();
        if (val >= query) {
          // The smallest neighbor is still larger than the `query`, so no need
          // to keep exploring. Re-push (i, j, grid[i][j]) back to the
          // `minHeap`.
          minHeap.emplace(i, j, val);
          break;
        }
        ++accumulate;
        for (int k = 0; k < 4; ++k) {
          const int x = i + dirs[k];
          const int y = j + dirs[k + 1];
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          if (seen[x][y])
            continue;
          minHeap.emplace(x, y, grid[x][y]);
          seen[x][y] = true;
        }
      }
      ans[queryIndex] = accumulate;
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

struct IndexedQuery {
  int queryIndex;
  int query;
};

struct T {
  int i;
  int j;
  int val;  // grid[i][j]
};

class Solution {
 public:
  vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
    constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const int m = grid.size();
    const int n = grid[0].size();
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
          // The smallest neighbor is still larger than `query`, so no need to
          // keep exploring. Re-push (i, j, grid[i][j]) back to the `minHeap`.
          minHeap.emplace(i, j, val);
          break;
        }
        ++accumulate;
        for (const auto& [dx, dy] : dirs) {
          const int x = i + dx;
          const int y = j + dy;
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
    ranges::sort(
        indexedQueries, ranges::less{},
        [](const IndexedQuery& indexedQuery) { return indexedQuery.query; });
    return indexedQueries;
  }
};

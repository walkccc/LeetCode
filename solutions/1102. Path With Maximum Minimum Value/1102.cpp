struct T {
  int i;
  int j;
  int val;
};

class Solution {
 public:
  int maximumMinimumPath(vector<vector<int>>& A) {
    const int m = A.size();
    const int n = A[0].size();
    const vector<int> dirs{0, 1, 0, -1, 0};

    int ans = A[0][0];
    vector<vector<bool>> seen(m, vector<bool>(n));
    auto compare = [](const T& a, const T& b) { return a.val < b.val; };
    priority_queue<T, vector<T>, decltype(compare)> pq(compare);

    pq.push({0, 0, A[0][0]});

    while (!pq.empty()) {
      const auto [i, j, val] = pq.top();
      pq.pop();
      ans = min(ans, val);
      if (i == m - 1 && j == n - 1)
        return ans;
      seen[i][j] = true;
      for (int k = 0; k < 4; ++k) {
        const int x = i + dirs[k];
        const int y = j + dirs[k + 1];
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        if (seen[x][y])
          continue;
        pq.push({x, y, A[x][y]});
      }
    }

    throw;
  }
};

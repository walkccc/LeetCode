class Solution {
 public:
  int minimumLines(vector<vector<int>>& points) {
    const int allCovered = (1 << points.size()) - 1;
    return dfs(points, 0, allCovered, vector<int>(allCovered, -1));
  }

 private:
  int dfs(const vector<vector<int>>& points, int covered, int allCovered,
          vector<int>&& memo) {
    if (covered == allCovered)
      return 0;
    if (memo[covered] != -1)
      return memo[covered];

    const int n = points.size();
    int ans = n / 2 + (n & 1);

    for (int i = 0; i < n; ++i) {
      if (covered >> i & 1)
        continue;
      for (int j = 0; j < n; ++j) {
        if (i == j)
          continue;
        // Connect the points[i] with the points[j].
        int newCovered = covered | 1 << i | 1 << j;
        // Mark the points covered by this line.
        const pair<int, int> slope = getSlope(points[i], points[j]);
        for (int k = 0; k < n; ++k)
          if (getSlope(points[i], points[k]) == slope)
            newCovered |= 1 << k;
        ans = min(ans, 1 + dfs(points, newCovered, allCovered, move(memo)));
      }
    }

    return memo[covered] = ans;
  }

  pair<int, int> getSlope(const vector<int>& p, const vector<int>& q) {
    const int dx = p[0] - q[0];
    const int dy = p[1] - q[1];
    if (dx == 0)
      return {0, p[0]};
    if (dy == 0)
      return {p[1], 0};
    const int d = __gcd(dx, dy);
    const int x = dx / d;
    const int y = dy / d;
    if (x > 0)
      return {x, y};
    return {-x, -y};
  }
};

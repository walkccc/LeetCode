class Solution {
 public:
  vector<int> distributeCandies(int candies, long n) {
    vector<int> ans(n);
    int rows = (-n + sqrt(n * n + 8 * n * n * candies)) / (2 * n * n);
    int accumN = rows * (rows - 1) * n / 2;

    for (int i = 0; i < n; ++i)
      ans[i] = accumN + rows * (i + 1);

    int givenCandies = (n * n * rows * rows + n * rows) / 2;
    candies -= givenCandies;

    for (int i = 0, lastGiven = rows * n + 1; candies > 0; ++i, ++lastGiven) {
      int actualGiven = min(lastGiven, candies);
      candies -= actualGiven;
      ans[i] += actualGiven;
    }

    return ans;
  }
};

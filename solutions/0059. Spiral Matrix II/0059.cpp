class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n));
    int count = 1;

    for (int min = 0; min < n / 2; ++min) {
      const int max = n - min - 1;
      for (int i = min; i < max; ++i)
        ans[min][i] = count++;
      for (int i = min; i < max; ++i)
        ans[i][max] = count++;
      for (int i = max; i > min; --i)
        ans[max][i] = count++;
      for (int i = max; i > min; --i)
        ans[i][min] = count++;
    }

    if (n & 1)
      ans[n / 2][n / 2] = count;

    return ans;
  }
};

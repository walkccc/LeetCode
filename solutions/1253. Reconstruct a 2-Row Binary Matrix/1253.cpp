class Solution {
 public:
  vector<vector<int>> reconstructMatrix(int upper, int lower,
                                        vector<int>& colsum) {
    if (upper + lower != accumulate(colsum.begin(), colsum.end(), 0))
      return {};
    if (min(upper, lower) <
        ranges::count_if(colsum, [](int c) { return c == 2; }))
      return {};

    vector<vector<int>> ans(2, vector<int>(colsum.size()));

    for (int j = 0; j < colsum.size(); ++j)
      if (colsum[j] == 2) {
        ans[0][j] = 1;
        ans[1][j] = 1;
        --upper;
        --lower;
      }

    for (int j = 0; j < colsum.size(); ++j) {
      if (colsum[j] == 1 && upper > 0) {
        ans[0][j] = 1;
        --colsum[j];
        --upper;
      }

      if (colsum[j] == 1 && lower > 0) {
        ans[1][j] = 1;
        --lower;
      }
    }

    return ans;
  }
};

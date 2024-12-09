class Solution {
 public:
  vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
    vector<int> ans{0, 0};

    for (int i = 0; i < mat.size(); ++i) {
      const int ones = ranges::count(mat[i], 1);
      if (ones > ans[1]) {
        ans[0] = i;
        ans[1] = ones;
      }
    }

    return ans;
  }
};

class Solution {
 public:
  int minDeletionSize(vector<string>& strs) {
    int ans = 0;

    for (int j = 0; j < strs[0].length(); ++j)
      for (int i = 0; i + 1 < strs.size(); ++i)
        if (strs[i][j] > strs[i + 1][j]) {
          ++ans;
          break;
        }

    return ans;
  }
};

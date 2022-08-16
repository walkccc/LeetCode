class Solution {
 public:
  vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    const int m = box.size();
    const int n = box[0].size();
    vector<vector<char>> ans(n, vector<char>(m, '.'));

    for (int i = 0; i < m; ++i)
      for (int j = n - 1, k = n - 1; j >= 0; --j)
        if (box[i][j] != '.') {
          if (box[i][j] == '*')
            k = j;
          ans[k--][m - i - 1] = box[i][j];
        }

    return ans;
  }
};

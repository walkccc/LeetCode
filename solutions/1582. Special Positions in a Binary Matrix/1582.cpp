class Solution {
 public:
  int numSpecial(vector<vector<int>>& mat) {
    const int m = mat.size();
    const int n = mat[0].size();
    int ans = 0;
    vector<int> rowOnes(m);
    vector<int> colOnes(n);

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (mat[i][j] == 1) {
          ++rowOnes[i];
          ++colOnes[j];
        }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (mat[i][j] == 1 && rowOnes[i] == 1 && colOnes[j] == 1)
          ++ans;

    return ans;
  }
};

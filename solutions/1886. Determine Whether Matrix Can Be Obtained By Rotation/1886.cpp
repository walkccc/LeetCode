class Solution {
 public:
  bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    for (int i = 0; i < 4; ++i) {
      if (mat == target)
        return true;
      rotate(mat);
    }
    return false;
  }

 private:
  void rotate(vector<vector<int>>& M) {
    reverse(M.begin(), M.end());
    for (int i = 0; i < M.size(); ++i)
      for (int j = i + 1; j < M.size(); ++j)
        swap(M[i][j], M[j][i]);
  }
};

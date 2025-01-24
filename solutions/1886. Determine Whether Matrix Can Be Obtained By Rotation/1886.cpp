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
  void rotate(vector<vector<int>>& mat) {
    ranges::reverse(mat);
    for (int i = 0; i < mat.size(); ++i)
      for (int j = i + 1; j < mat.size(); ++j)
        swap(mat[i][j], mat[j][i]);
  }
};

class Solution {
 public:
  vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int l = 0;
    int r = mat.size() - 1;

    while (l < r) {
      const int m = (l + r) / 2;
      if (ranges::max(mat[m]) >= ranges::max(mat[m + 1]))
        r = m;
      else
        l = m + 1;
    }

    return {l, getMaxIndex(mat[l])};
  }

 private:
  int getMaxIndex(const vector<int>& A) {
    pair<int, int> res{0, A[0]};
    for (int i = 1; i < A.size(); ++i)
      if (A[i] > res.second)
        res = {i, A[i]};
    return res.first;
  }
};

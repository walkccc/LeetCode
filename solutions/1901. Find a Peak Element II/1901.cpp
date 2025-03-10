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
  int getMaxIndex(const vector<int>& arr) {
    pair<int, int> res{0, arr[0]};
    for (int i = 1; i < arr.size(); ++i)
      if (arr[i] > res.second)
        res = {i, arr[i]};
    return res.first;
  }
};

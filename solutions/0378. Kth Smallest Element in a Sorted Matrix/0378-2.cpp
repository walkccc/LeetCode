class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int l = matrix[0][0];
    int r = matrix.back().back();

    while (l < r) {
      const int m = l + (r - l) / 2;
      if (numsNoGreaterThan(matrix, m) >= k)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

 private:
  int numsNoGreaterThan(const vector<vector<int>>& matrix, int m) {
    int count = 0;
    int j = matrix[0].size() - 1;
    // For each row, find the first index j s.t. row[j] <= m s.t. the number of
    // numbers <= m for this row will be j + 1.
    for (const vector<int>& row : matrix) {
      while (j >= 0 && row[j] > m)
        --j;
      count += j + 1;
    }
    return count;
  }
};

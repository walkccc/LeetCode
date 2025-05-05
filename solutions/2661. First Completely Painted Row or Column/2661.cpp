class Solution {
 public:
  int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    const int m = mat.size();
    const int n = mat[0].size();
    // rows[i] := the number of painted grid in the i-th row
    vector<int> rows(m);
    // cols[j] := the number of painted grid in the j-th column
    vector<int> cols(n);
    // numToRow[num] := the i-th row of `num` in `mat`
    vector<int> numToRow(m * n + 1);
    // numToCol[num] := the j-th column of `num` in `mat`
    vector<int> numToCol(m * n + 1);

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        numToRow[mat[i][j]] = i;
        numToCol[mat[i][j]] = j;
      }

    for (int i = 0; i < arr.size(); ++i) {
      if (++rows[numToRow[arr[i]]] == n)
        return i;
      if (++cols[numToCol[arr[i]]] == m)
        return i;
    }

    throw;
  }
};

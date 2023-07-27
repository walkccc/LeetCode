class Solution {
 public:
  int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    const int m = mat.size();
    const int n = mat[0].size();
    // rows[i] := # of painted grid in i-th row
    vector<int> rows(m);
    // cols[j] := # of painted grid in j-th col
    vector<int> cols(n);
    // numToRow[num] := i-th row of num in mat
    vector<int> numToRow(m * n + 1);
    // numToCol[num] := j-th col of num in mat
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

class Solution {
 public:
  int oddCells(int m, int n, vector<vector<int>>& indices) {
    // rows[i] and cols[i] :=
    //   1. true (flipped even times)
    //   2. false (flipped odd times)
    vector<bool> rows(m);
    vector<bool> cols(n);

    for (const vector<int>& index : indices) {
      rows[index[0]] = rows[index[0]] ^ true;
      cols[index[1]] = cols[index[1]] ^ true;
    }

    const int oddRowsCount = ranges::count(rows, true);
    const int oddColsCount = ranges::count(cols, true);
    const int evenRowsCount = m - oddRowsCount;
    const int evenColsCount = n - oddColsCount;
    return oddRowsCount * evenColsCount + oddColsCount * evenRowsCount;
  }
};

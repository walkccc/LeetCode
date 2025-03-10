class Solution {
 public:
  int oddCells(int m, int n, vector<vector<int>>& indices) {
    unordered_set<int> oddRows;
    unordered_set<int> oddCols;

    for (const vector<int>& index : indices) {
      const int r = index[0];
      const int c = index[1];
      if (!oddRows.insert(r).second)
        oddRows.erase(r);
      if (!oddCols.insert(c).second)
        oddCols.erase(c);
    }

    return oddRows.size() * (n - oddCols.size()) +
           oddCols.size() * (m - oddRows.size());
  }
};

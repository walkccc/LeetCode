class Solution {
 public:
  int oddCells(int m, int n, vector<vector<int>>& indices) {
    int ans = 0;
    // rows[i] and cols[i] :=
    //   true (flipped even times) / false (flipped odd times)
    vector<bool> rows(m);
    vector<bool> cols(n);

    for (const vector<int>& index : indices) {
      rows[index[0]] = rows[index[0]] ^ true;
      cols[index[1]] = cols[index[1]] ^ true;
    }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        ans += rows[i] ^ cols[j];

    return ans;
  }
};

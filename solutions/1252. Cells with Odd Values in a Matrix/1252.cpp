class Solution {
 public:
  int oddCells(int n, int m, vector<vector<int>>& indices) {
    int ans = 0;
    vector<int> rows(n);
    vector<int> cols(m);

    for (vector<int>& indice : indices) {
      rows[indice[0]] ^= 1;
      cols[indice[1]] ^= 1;
    }

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        ans += rows[i] ^ cols[j];

    return ans;
  }
};

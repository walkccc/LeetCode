class Solution {
 public:
  int findLonelyPixel(vector<vector<char>>& picture) {
    const int m = picture.size();
    const int n = picture[0].size();
    int ans = 0;
    vector<int> rows(m);  // rows[i] := the number of B's in rows i
    vector<int> cols(n);  // cols[i] := the number of B's in cols i

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (picture[i][j] == 'B') {
          ++rows[i];
          ++cols[j];
        }

    for (int i = 0; i < m; ++i)
      if (rows[i] == 1)  // Only have to examine the rows if rows[i] == 1.
        for (int j = 0; j < n; ++j)
          // After meeting a 'B' in this rows, break and search the next row.
          if (picture[i][j] == 'B') {
            if (cols[j] == 1)
              ++ans;
            break;
          }

    return ans;
  }
};

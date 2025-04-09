class Solution {
 public:
  int findBlackPixel(vector<vector<char>>& picture, int target) {
    const int m = picture.size();
    const int n = picture[0].size();
    int ans = 0;
    vector<int> rows(m);
    vector<int> cols(n);
    vector<string> rowStrings(m);
    unordered_map<string, int> countRowStrings;

    for (int i = 0; i < m; ++i) {
      string s;
      for (int j = 0; j < n; ++j) {
        if (picture[i][j] == 'B') {
          ++rows[i];
          ++cols[j];
        }
        s += picture[i][j];
      }
      rowStrings[i] = s;
      ++countRowStrings[s];
    }

    for (int i = 0; i < m; ++i)
      if (rows[i] == target && countRowStrings[rowStrings[i]] == target)
        for (int j = 0; j < n; ++j)
          if (picture[i][j] == 'B' && cols[j] == target)
            ++ans;

    return ans;
  }
};

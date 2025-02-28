class Solution {
 public:
  vector<int> gridIllumination(int n, vector<vector<int>>& lamps,
                               vector<vector<int>>& queries) {
    vector<int> ans;
    unordered_map<int, int> rows;
    unordered_map<int, int> cols;
    unordered_map<int, int> diag1;
    unordered_map<int, int> diag2;
    unordered_set<pair<int, int>, PairHash> lampsSet;

    for (const vector<int>& lamp : lamps) {
      const int i = lamp[0];
      const int j = lamp[1];
      if (lampsSet.insert({i, j}).second) {
        ++rows[i];
        ++cols[j];
        ++diag1[i + j];
        ++diag2[i - j];
      }
    }

    for (const vector<int>& query : queries) {
      const int i = query[0];
      const int j = query[1];
      if (rows[i] || cols[j] || diag1[i + j] || diag2[i - j]) {
        ans.push_back(1);
        for (int y = max(0, i - 1); y < min(n, i + 2); ++y)
          for (int x = max(0, j - 1); x < min(n, j + 2); ++x)
            if (lampsSet.erase({y, x})) {
              --rows[y];
              --cols[x];
              --diag1[y + x];
              --diag2[y - x];
            }
      } else {
        ans.push_back(0);
      }
    }

    return ans;
  }

 private:
  struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
      return p.first ^ p.second;
    }
  };
};

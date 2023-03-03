class Solution {
 public:
  vector<vector<int>> largeGroupPositions(string s) {
    const int n = s.length();
    vector<vector<int>> ans;

    for (int i = 0, j = 0; i < n; i = j) {
      while (j < n && s[j] == s[i])
        ++j;
      if (j - i >= 3)
        ans.push_back({i, j - 1});
    }

    return ans;
  }
};

class Solution {
 public:
  vector<vector<int>> largeGroupPositions(string S) {
    const int n = S.length();
    vector<vector<int>> ans;

    for (int i = 0, j = 0; i < n; i = j) {
      while (j < n && S[j] == S[i])
        ++j;
      if (j - i >= 3)
        ans.push_back({i, j - 1});
    }

    return ans;
  }
};

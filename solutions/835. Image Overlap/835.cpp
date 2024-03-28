class Solution {
 public:
  int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
    const int n = A.size();
    const int magic = 100;
    int ans = 0;
    vector<pair<int, int>> onesA;
    vector<pair<int, int>> onesB;
    unordered_map<int, int> map;

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        if (A[i][j] == 1)
          onesA.emplace_back(i, j);
        if (B[i][j] == 1)
          onesB.emplace_back(i, j);
      }

    for (const pair<int, int>& a : onesA)
      for (const pair<int, int>& b : onesB)
        ++map[(a.first - b.first) * magic + (a.second - b.second)];

    for (const auto& [_, value] : map)
      ans = max(ans, value);

    return ans;
  }
};

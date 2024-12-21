class Solution {
 public:
  int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
    constexpr int kMagic = 100;
    const int n = img1.size();
    int ans = 0;
    vector<pair<int, int>> ones1;
    vector<pair<int, int>> ones2;
    unordered_map<int, int> offsetCount;

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        if (img1[i][j] == 1)
          ones1.emplace_back(i, j);
        if (img2[i][j] == 1)
          ones2.emplace_back(i, j);
      }

    for (const auto& [ax, ay] : ones1)
      for (const auto& [bx, by] : ones2)
        ++offsetCount[(ax - bx) * kMagic + (ay - by)];

    for (const auto& [_, count] : offsetCount)
      ans = max(ans, count);

    return ans;
  }
};

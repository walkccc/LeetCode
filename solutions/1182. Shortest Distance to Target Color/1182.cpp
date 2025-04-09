class Solution {
 public:
  vector<int> shortestDistanceColor(vector<int>& colors,
                                    vector<vector<int>>& queries) {
    constexpr int kNumColor = 3;
    const int n = colors.size();
    vector<int> ans;
    // left[i][c] := the closest index of color c in index i to the left
    vector<vector<int>> left(n, vector<int>(kNumColor + 1));
    // right[i][c] := the closest index of color c in index i to the right
    vector<vector<int>> right(n, vector<int>(kNumColor + 1));

    vector<int> colorToClosestIndex{0, -1, -1, -1};  // 0-indexed, -1 := N/A
    for (int i = 0; i < n; ++i) {
      colorToClosestIndex[colors[i]] = i;
      for (int c = 1; c <= kNumColor; ++c)
        left[i][c] = colorToClosestIndex[c];
    }

    colorToClosestIndex = {0, -1, -1, -1};  // Reset.
    for (int i = n - 1; i >= 0; --i) {
      colorToClosestIndex[colors[i]] = i;
      for (int c = 1; c <= kNumColor; ++c)
        right[i][c] = colorToClosestIndex[c];
    }

    for (const vector<int>& query : queries) {
      const int i = query[0];
      const int c = query[1];
      const int leftDist = left[i][c] == -1 ? INT_MAX : i - left[i][c];
      const int rightDist = right[i][c] == -1 ? INT_MAX : right[i][c] - i;
      const int minDist = min(leftDist, rightDist);
      ans.push_back(minDist == INT_MAX ? -1 : minDist);
    }

    return ans;
  }
};

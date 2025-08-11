class Solution {
 public:
  vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
    const int m = s.length();
    const int uMost = startPos[0] + 1;
    const int dMost = n - startPos[0];
    const int lMost = startPos[1] + 1;
    const int rMost = n - startPos[1];
    const unordered_map<char, pair<int, int>> moves{
        {'L', {0, -1}},
        {'R', {0, 1}},
        {'U', {-1, 0}},
        {'D', {1, 0}},
    };

    vector<int> ans(m);
    unordered_map<int, int> reachX{{0, m}};
    unordered_map<int, int> reachY{{0, m}};
    int x = 0;
    int y = 0;

    for (int i = m - 1; i >= 0; --i) {
      const auto& [dx, dy] = moves.at(s[i]);
      x -= dx;
      y -= dy;
      reachX[x] = i;
      reachY[y] = i;
      int out = INT_MAX;
      if (const auto it = reachX.find(x - uMost); it != reachX.cend())
        out = min(out, it->second);
      if (const auto it = reachX.find(x + dMost); it != reachX.cend())
        out = min(out, it->second);
      if (const auto it = reachY.find(y - lMost); it != reachY.cend())
        out = min(out, it->second);
      if (const auto it = reachY.find(y + rMost); it != reachY.cend())
        out = min(out, it->second);
      ans[i] = out == INT_MAX ? m - i : out - i - 1;
    }

    return ans;
  }
};

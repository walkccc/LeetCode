class Solution {
 public:
  int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    const vector<int> dirs{0, 1, 0, -1, 0};
    int ans = 0;
    int d = 0;  // 0 := north, 1 := east, 2 := south, 3 := west
    int x = 0;  // start x
    int y = 0;  // start y
    unordered_set<pair<int, int>, pairHash> obstaclesSet;

    for (const auto& o : obstacles)
      obstaclesSet.insert({o[0], o[1]});

    for (const int c : commands) {
      if (c == -1) {
        d = (d + 1) % 4;
      } else if (c == -2) {
        d = (d + 3) % 4;
      } else {
        for (int step = 0; step < c; ++step) {
          if (obstaclesSet.count({x + dirs[d], y + dirs[d + 1]}))
            break;
          x += dirs[d];
          y += dirs[d + 1];
        }
      }
      ans = max(ans, x * x + y * y);
    }

    return ans;
  }

 private:
  struct pairHash {
    size_t operator()(const pair<int, int>& p) const {
      return p.first ^ p.second;
    }
  };
};

class Solution {
 public:
  int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    constexpr int kDirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int ans = 0;
    int d = 0;  // 0 := north, 1 := east, 2 := south, 3 := west
    int x = 0;  // the start x
    int y = 0;  // the start y
    unordered_set<pair<int, int>, PairHash> obstaclesSet;

    for (const vector<int>& obstacle : obstacles) {
      const int x = obstacle[0];
      const int y = obstacle[1];
      obstaclesSet.insert({x, y});
    }

    for (const int command : commands) {
      if (command == -1) {
        d = (d + 1) % 4;
      } else if (command == -2) {
        d = (d + 3) % 4;
      } else {
        for (int step = 0; step < command; ++step) {
          if (obstaclesSet.contains({x + kDirs[d][0], y + kDirs[d][1]}))
            break;
          x += kDirs[d][0];
          y += kDirs[d][1];
        }
      }
      ans = max(ans, x * x + y * y);
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

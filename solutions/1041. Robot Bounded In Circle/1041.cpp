class Solution {
 public:
  bool isRobotBounded(string instructions) {
    int x = 0;
    int y = 0;
    int d = 0;
    vector<vector<int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for (char instruction : instructions) {
      if (instruction == 'G') {
        x += directions[d][0];
        y += directions[d][1];
      } else if (instruction == 'L')
        d = (d + 3) % 4;
      else
        d = (d + 1) % 4;
    }

    return x == 0 && y == 0 || d > 0;
  }
};

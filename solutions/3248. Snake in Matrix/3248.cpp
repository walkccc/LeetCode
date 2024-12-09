class Solution {
 public:
  int finalPositionOfSnake(int n, vector<string>& commands) {
    const unordered_map<string, pair<int, int>> directions = {
        {"UP", {-1, 0}},
        {"RIGHT", {0, 1}},
        {"DOWN", {1, 0}},
        {"LEFT", {0, -1}}};
    int i = 0;
    int j = 0;

    for (const string& command : commands) {
      const auto& [dx, dy] = directions.at(command);
      i += dx;
      j += dy;
    }

    return i * n + j;
  }
};

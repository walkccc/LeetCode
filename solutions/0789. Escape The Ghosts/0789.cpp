class Solution {
 public:
  bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
    const int d = abs(target[0]) + abs(target[1]);

    for (const auto& ghost : ghosts)
      if (d >= abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]))
        return false;

    return true;
  }
};

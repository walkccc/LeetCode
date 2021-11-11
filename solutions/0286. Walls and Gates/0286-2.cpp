class Solution {
 public:
  void wallsAndGates(vector<vector<int>>& rooms) {
    for (int i = 0; i < rooms.size(); ++i)
      for (int j = 0; j < rooms[0].size(); ++j)
        if (rooms[i][j] == 0)
          dfs(rooms, i, j, 0);
  }

 private:
  void dfs(vector<vector<int>>& rooms, int i, int j, int distance) {
    if (i < 0 || i == rooms.size() || j < 0 || j == rooms[0].size())
      return;
    if (rooms[i][j] < distance)
      return;

    rooms[i][j] = distance;
    dfs(rooms, i + 1, j, distance + 1);
    dfs(rooms, i - 1, j, distance + 1);
    dfs(rooms, i, j + 1, distance + 1);
    dfs(rooms, i, j - 1, distance + 1);
  }
};

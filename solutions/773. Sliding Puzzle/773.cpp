class Solution {
 public:
  int slidingPuzzle(vector<vector<int>>& board) {
    constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    constexpr int m = 2;
    constexpr int n = 3;
    constexpr char goal[] = "123450";
    string start;

    // Hash the 2D vector into a string.
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        start += '0' + board[i][j];

    if (start == goal)
      return 0;

    queue<string> q{{start}};
    unordered_set<string> seen{start};

    for (int step = 1; !q.empty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        string s = q.front();
        q.pop();
        const int zeroIndex = s.find('0');
        const int i = zeroIndex / n;
        const int j = zeroIndex % n;
        for (const auto& [dx, dy] : dirs) {
          const int x = i + dx;
          const int y = j + dy;
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          const int swappedIndex = x * n + y;
          swap(s[zeroIndex], s[swappedIndex]);
          if (s == goal)
            return step;
          if (!seen.contains(s)) {
            q.push(s);
            seen.insert(s);
          }
          swap(s[zeroIndex], s[swappedIndex]);
        }
      }

    return -1;
  }
};

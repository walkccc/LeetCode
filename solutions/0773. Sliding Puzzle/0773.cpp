class Solution {
 public:
  int slidingPuzzle(vector<vector<int>>& board) {
    constexpr int m = 2;
    constexpr int n = 3;
    const vector<int> dirs{0, 1, 0, -1, 0};
    const string goal = "123450";
    int steps = 0;
    string start;

    // hash 2D vector to string
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        start += '0' + board[i][j];

    if (start == goal)
      return 0;

    queue<string> q{{start}};
    unordered_set<string> seen{start};

    while (!q.empty()) {
      ++steps;
      for (int sz = q.size(); sz > 0; --sz) {
        string s = q.front();
        q.pop();
        const int zeroIndex = s.find('0');
        const int i = zeroIndex / n;
        const int j = zeroIndex % n;
        for (int k = 0; k < 4; ++k) {
          const int x = i + dirs[k];
          const int y = j + dirs[k + 1];
          if (x < 0 || x == m || y < 0 || y == n)
            continue;
          const int swappedIndex = x * n + y;
          swap(s[zeroIndex], s[swappedIndex]);
          if (s == goal)
            return steps;
          if (!seen.count(s)) {
            q.push(s);
            seen.insert(s);
          }
          swap(s[zeroIndex], s[swappedIndex]);
        }
      }
    }

    return -1;
  }
};

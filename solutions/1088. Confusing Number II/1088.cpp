class Solution {
 public:
  int confusingNumberII(int n) {
    return dfs(n, 0, 0, 1);
  }

 private:
  vector<pair<int, int>> digitToRotated{{0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}};

  int dfs(int n, long num, long rotatedNum, long unit) {
    int ans = num != rotatedNum;
    // add one more digit
    for (const auto& [digit, rotated] : digitToRotated) {
      if (digit == 0 && num == 0)
        continue;
      const long nextNum = num * 10 + digit;
      if (nextNum > n)
        break;
      ans += dfs(n, nextNum, rotated * unit + rotatedNum, unit * 10);
    }
    return ans;
  }
};

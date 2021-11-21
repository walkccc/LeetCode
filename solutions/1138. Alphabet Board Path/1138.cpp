class Solution {
 public:
  string alphabetBoardPath(string target) {
    string ans;
    int x = 0;
    int y = 0;

    for (char c : target) {
      int newX = (c - 'a') % 5;
      int newY = (c - 'a') / 5;
      ans += string(max(0, y - newY), 'U') + string(max(0, newX - x), 'R') +
             string(max(0, x - newX), 'L') + string(max(0, newY - y), 'D') +
             '!';
      x = newX;
      y = newY;
    }

    return ans;
  }
};

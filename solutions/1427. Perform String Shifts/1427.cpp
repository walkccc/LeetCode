class Solution {
 public:
  string stringShift(string s, vector<vector<int>>& shift) {
    const int n = s.length();
    int move = 0;

    for (const vector<int>& pair : shift) {
      const int direction = pair[0];
      const int amount = pair[1];
      if (direction == 0)
        move -= amount;
      else
        move += amount;
    }

    move = ((move % n) + n) % n;
    return s.substr(n - move) + s.substr(0, n - move);
  }
};

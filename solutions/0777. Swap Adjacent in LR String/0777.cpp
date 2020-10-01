class Solution {
 public:
  bool canTransform(string start, string end) {
    int i = 0;  // point to start
    int j = 0;  // point to end

    while (i < start.length()) {
      while (start[i] == 'X') ++i;
      while (end[j] == 'X') ++j;
      if (start[i] != end[j]) return false;
      if (start[i] == 'R' && i > j) return false;
      if (start[i] == 'L' && i < j) return false;
      ++i;
      ++j;
    }

    return true;
  }
};
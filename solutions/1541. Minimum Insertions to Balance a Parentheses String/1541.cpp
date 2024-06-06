class Solution {
 public:
  int minInsertions(string s) {
    int neededRight = 0;   // Increment by 2 for each '('.
    int missingLeft = 0;   // Increment by 1 for each missing '('.
    int missingRight = 0;  // Increment by 1 for each missing ')'.

    for (const char c : s)
      if (c == '(') {
        if (neededRight % 2 == 1) {
          // e.g. "()(..."
          ++missingRight;
          --neededRight;
        }
        neededRight += 2;
      } else if (--neededRight < 0) {  // c == ')'
        // e.g. "()))..."
        ++missingLeft;
        neededRight += 2;
      }

    return neededRight + missingLeft + missingRight;
  }
};

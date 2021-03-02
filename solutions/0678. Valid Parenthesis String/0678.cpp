class Solution {
 public:
  bool checkValidString(const string& s) {
    int low = 0;   // lower bound of valid '(' count
    int high = 0;  // upper bound of valid '(' count

    for (const char c : s) {
      switch (c) {
        case '(':
          ++low;
          ++high;
          break;
        case ')':
          low = max(0, --low);
          --high;
          break;
        case '*':
          low = max(0, --low);
          ++high;
          break;
      }
      if (high < 0)
        return false;
    }

    return low == 0;
  }
};

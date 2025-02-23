class Solution {
 public:
  bool checkValidString(const string& s) {
    int low = 0;   // the lower bound of the number of valid '('s
    int high = 0;  // the upper bound of the number of valid '('s

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

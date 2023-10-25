class Solution {
 public:
  bool checkRecord(string s) {
    int countA = 0;
    int countL = 0;

    for (const char c : s) {
      if (c == 'A' && ++countA > 1)
        return false;
      if (c != 'L')
        countL = 0;
      else if (++countL > 2)
        return false;
    }

    return true;
  }
};

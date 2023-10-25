class Solution {
 public:
  int furthestDistanceFromOrigin(string moves) {
    int countL = 0;
    int countR = 0;
    int countUnderline = 0;

    for (const char c : moves)
      if (c == 'L')
        ++countL;
      else if (c == 'R')
        ++countR;
      else  // c == '_'
        ++countUnderline;

    return abs(countL - countR) + countUnderline;
  }
};

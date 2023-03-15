class Solution {
 public:
  string longestDiverseString(int a, int b, int c, char A = 'a', char B = 'b',
                              char C = 'c') {
    if (a < b)
      return longestDiverseString(b, a, c, B, A, C);
    if (b < c)
      return longestDiverseString(a, c, b, A, C, B);
    if (b == 0)
      return string(min(a, 2), A);

    const int useA = min(a, 2);
    const int useB = (a - useA >= b) ? 1 : 0;
    return string(useA, A) + string(useB, B) +
           longestDiverseString(a - useA, b - useB, c, A, B, C);
  }
};

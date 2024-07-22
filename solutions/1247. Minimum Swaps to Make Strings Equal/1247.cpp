class Solution {
 public:
  int minimumSwap(string s1, string s2) {
    // ("xx", "yy") = (2 "xy"s) -> 1 swap
    // ("yy", "xx") = (2 "yx"s) -> 1 swap
    // ("xy", "yx") = (1 "xy" and 1 "yx") -> 2 swaps
    int xy = 0;  // the number of indices i's s.t. s1[i] = 'x' and s2[i] 'y'
    int yx = 0;  // the number of indices i's s.t. s1[i] = 'y' and s2[i] 'x'

    for (int i = 0; i < s1.length(); ++i) {
      if (s1[i] == s2[i])
        continue;
      if (s1[i] == 'x')
        ++xy;
      else
        ++yx;
    }

    if ((xy + yx) % 2 == 1)
      return -1;
    return xy / 2 + yx / 2 + (xy % 2 == 1 ? 2 : 0);
  }
};

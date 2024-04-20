class Solution {
 public:
  int numberOfCuts(int n) {
    if (n == 1)
      return 0;
    return n & 1 ? n : n / 2;
  }
};

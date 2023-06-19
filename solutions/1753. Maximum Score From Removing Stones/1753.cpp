class Solution {
 public:
  int maximumScore(int a, int b, int c) {
    // Max <= min + mid
    const int x = (a + b + c) / 2;
    // Max > min + mid
    const int y = a + b + c - max({a, b, c});
    return min(x, y);
  }
};

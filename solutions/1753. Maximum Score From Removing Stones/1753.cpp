class Solution {
 public:
  int maximumScore(int a, int b, int c) {
    // max <= min + mid
    const int x = (a + b + c) / 2;
    // max > min + mid
    const int y = a + b + c - max({a, b, c});
    return min(x, y);
  }
};

class Solution {
 public:
  int numberOfChild(int n, int k) {
    // the time for the ball to return to 0
    const int roundTime = 2 * (n - 1);
    const int pos = k % roundTime;
    return pos < n ? pos : roundTime - pos;
  }
};

class Solution {
 public:
  int minOperations(int k) {
    // The required operations are
    //   1. Increase `1` to `x`
    //   2. Duplicate `x`, `y` times, to `sum` s.t. x * (1 + y) >= k.
    // The number of operations used would be (x - 1) + y. Equivalently, the
    // problem can be rephrased as finding min(x - 1 + y) s.t. x * (1 + y) >= k.
    // Optimally, `x` should equal to `1 + y`, implying that x^2 >= k, and
    // hence, x >= sqrt(k) and y = ceil(k / x) - 1.
    const int x = sqrt(k);
    const int y = (k - 1) / x + 1 - 1;  // ceil(k / x) - 1
    return x - 1 + y;
  }
};

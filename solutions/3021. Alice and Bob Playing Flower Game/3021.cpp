class Solution {
 public:
  long long flowerGame(int n, int m) {
    // Alice wins if x + y is odd, occurring when:
    //   1. x is even and y is odd, or
    //   2. y is even and x is odd.
    const int xEven = n / 2;
    const int yEven = m / 2;
    const int xOdd = (n + 1) / 2;
    const int yOdd = (m + 1) / 2;
    return static_cast<long>(xEven) * yOdd + static_cast<long>(yEven) * xOdd;
  }
};

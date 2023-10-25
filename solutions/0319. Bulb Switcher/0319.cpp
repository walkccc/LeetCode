class Solution {
 public:
  int bulbSwitch(int n) {
    // K-th bulb only be switched when k % i == 0.
    // So we can reiterate the problem:
    // To find # of number <= n that have odd factors.
    // Obviously, only square numbers have odd factor(s).
    // E.g. n = 10, only 1, 4, and 9 are square numbers that <= 10
    return sqrt(n);
  }
};

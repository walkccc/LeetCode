class Solution {
 public:
  int sumOfMultiples(int n) {
    // Returns the sum of multiples of value in [1, n].
    auto sumOfMultiples = [n](int value) {
      const int lo = value;
      const int hi = n / value * value;
      const int count = (hi - lo) / value + 1;
      return (lo + hi) * count / 2;
    };
    return sumOfMultiples(3) + sumOfMultiples(5) + sumOfMultiples(7) -
           (sumOfMultiples(15) + sumOfMultiples(21) + sumOfMultiples(35)) +
           sumOfMultiples(105);
  }
};

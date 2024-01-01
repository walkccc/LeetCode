class Solution {
 public:
  int differenceOfSums(int n, int m) {
    const int sum = (1 + n) * n / 2;
    const int num2 = getDivisibleSum(n, m);
    const int num1 = sum - num2;
    return num1 - num2;
  }

 private:
  // Returns the sum of all the integers in [1, n] that are divisible by m.
  int getDivisibleSum(int n, int m) {
    const int last = n / m * m;
    if (last == 0)
      return 0;
    const int first = m;
    const int count = (last - first) / m + 1;
    return (first + last) * count / 2;
  }
};

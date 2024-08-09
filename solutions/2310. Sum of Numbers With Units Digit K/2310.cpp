class Solution {
 public:
  int minimumNumbers(int num, int k) {
    if (num == 0)
      return 0;

    // Assume the size of the set is n, and the numbers in the set are X1, X2,
    // ..., Xn. Since the units digit of each number is k, X1 + X2 + ... + Xn =
    // N * k + 10 * (x1 + x2 + ... + xn) = num. Therefore, the goal is to find
    // the n s.t. n * k % 10 = num % 10
    for (int i = 1; i <= 10 && i * k <= num; ++i)
      if (i * k % 10 == num % 10)
        return i;

    return -1;
  }
};

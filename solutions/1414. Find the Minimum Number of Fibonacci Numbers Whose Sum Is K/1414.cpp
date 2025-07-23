class Solution {
 public:
  int findMinFibonacciNumbers(int k) {
    if (k < 2)  // k == 0 || k == 1
      return k;

    int a = 1;  // F_1
    int b = 1;  // F_2

    while (b <= k) {
      //    a, b = F_{i + 1}, F_{i + 2}
      // -> a, b = F_{i + 2}, F_{i + 3}
      const int temp = a;
      a = b;
      b = a + temp;
    }

    return 1 + findMinFibonacciNumbers(k - a);
  }
};

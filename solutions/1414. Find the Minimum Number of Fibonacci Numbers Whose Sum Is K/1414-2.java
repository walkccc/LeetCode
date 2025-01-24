class Solution {
  public int findMinFibonacciNumbers(int k) {
    int ans = 0;
    int a = 1; // F_1
    int b = 1; // F_2

    while (b <= k) {
      //    a, b = F_{i + 1}, F_{i + 2}
      // -> a, b = F_{i + 2}, F_{i + 3}
      final int temp = a;
      a = b;
      b = a + temp;
    }

    while (a > 0) {
      if (a <= k) {
        k -= a;
        ++ans;
      }
      //    a, b = F_{i + 2}, F_{i + 3}
      // -> a, b = F_{i + 1}, F_{i + 2}
      final int temp = a;
      a = b - a;
      b = temp;
    }

    return ans;
  }
}

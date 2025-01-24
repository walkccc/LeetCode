class Solution {
  public int smallestFactorization(int num) {
    if (num == 1)
      return 1;

    long ans = 0;
    long base = 1;

    for (int i = 9; i > 1; --i)
      while (num % i == 0) {
        num /= i;
        ans = base * i + ans;
        base *= 10;
      }

    return num == 1 && ans <= Integer.MAX_VALUE ? (int) ans : 0;
  }
}

class Solution {
  public boolean isUgly(int n) {
    if (n == 0)
      return false;

    for (final int prime : new int[] {2, 3, 5})
      while (n % prime == 0)
        n /= prime;

    return n == 1;
  }
}

class Solution {
  public boolean isUgly(int num) {
    if (num == 0)
      return false;

    for (final int prime : new int[] {2, 3, 5})
      while (num % prime == 0)
        num /= prime;

    return num == 1;
  }
}

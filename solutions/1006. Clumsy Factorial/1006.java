class Solution {
  public int clumsy(int n) {
    if (n == 1)
      return 1;
    if (n == 2)
      return 2;
    if (n == 3)
      return 6;
    if (n == 4)
      return 7;
    if (n % 4 == 1)
      return n + 2;
    if (n % 4 == 2)
      return n + 2;
    if (n % 4 == 3)
      return n - 1;
    return n + 1;
  }
}

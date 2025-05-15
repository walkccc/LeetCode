class Solution {
  public boolean isPerfectSquare(int num) {
    long l = 1;
    long r = num;

    while (l < r) {
      final long m = (l + r) / 2;
      if (m >= num / m)
        r = m;
      else
        l = m + 1;
    }

    return l * l == num;
  }
}

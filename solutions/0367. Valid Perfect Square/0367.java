class Solution {
  public boolean isPerfectSquare(int num) {
    long l = 1;
    long r = num;

    while (l < r) {
      final long m = l + (r - l) / 2;
      if (m < num / m)
        l = m + 1;
      else
        r = m;
    }

    return l * l == num;
  }
}
class Solution {
  public boolean judgeSquareSum(int c) {
    int l = 0;
    int r = (int) Math.sqrt(c);

    while (l <= r) {
      final int sum = l * l + r * r;
      if (sum == c)
        return true;
      if (sum < c)
        ++l;
      else
        --r;
    }

    return false;
  }
}

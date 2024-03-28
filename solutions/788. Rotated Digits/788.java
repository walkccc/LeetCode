class Solution {
  public int rotatedDigits(int n) {
    int ans = 0;

    for (int i = 1; i <= n; ++i)
      if (isGoodNumber(i))
        ++ans;

    return ans;
  }

  private boolean isGoodNumber(int i) {
    boolean isRotated = false;

    for (final char c : String.valueOf(i).toCharArray()) {
      if (c == '0' || c == '1' || c == '8')
        continue;
      if (c == '2' || c == '5' || c == '6' || c == '9')
        isRotated = true;
      else
        return false;
    }

    return isRotated;
  }
}

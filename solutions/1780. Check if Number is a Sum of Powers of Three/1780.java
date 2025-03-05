class Solution {
  public boolean checkPowersOfThree(int n) {
    while (n > 1) {
      final int r = n % 3;
      if (r == 2)
        return false;
      n /= 3;
    }

    return true;
  }
}

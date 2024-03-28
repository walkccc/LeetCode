class Solution {
  public boolean threeConsecutiveOdds(int[] arr) {
    int count = 0;
    for (final int a : arr) {
      count = a % 2 == 1 ? count + 1 : 0;
      if (count == 3)
        return true;
    }
    return false;
  }
}

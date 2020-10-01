class Solution {
  public boolean isPalindrome(int x) {
    if (x < 0)
      return false;

    long ans = 0;
    int y = x;

    while (y > 0) {
      ans = ans * 10 + y % 10;
      y /= 10;
    }

    return ans == x;
  }
}
class Solution {
  public boolean makePalindrome(String s) {
    int change = 0;
    int l = 0;
    int r = s.length() - 1;

    while (l < r) {
      if (s.charAt(l) != s.charAt(r) && ++change > 2)
        return false;
      ++l;
      --r;
    }

    return true;
  }
}

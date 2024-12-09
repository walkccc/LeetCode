class Solution {
  public int removePalindromeSub(String s) {
    return s.equals(new StringBuilder(s).reverse().toString()) ? 1 : 2;
  }
}

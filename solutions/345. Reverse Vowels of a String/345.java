class Solution {
  public String reverseVowels(String s) {
    StringBuilder sb = new StringBuilder(s);
    int l = 0;
    int r = s.length() - 1;

    while (l < r) {
      while (l < r && !isVowel(sb.charAt(l)))
        ++l;
      while (l < r && !isVowel(sb.charAt(r)))
        --r;
      sb.setCharAt(l, s.charAt(r));
      sb.setCharAt(r, s.charAt(l));
      ++l;
      --r;
    }

    return sb.toString();
  }

  private boolean isVowel(char c) {
    return "aeiouAEIOU".indexOf(c) != -1;
  }
}

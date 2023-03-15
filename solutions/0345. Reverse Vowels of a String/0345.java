class Solution {
  public String reverseVowels(String s) {
    final String vowels = "aeiouAEIOU";
    StringBuilder sb = new StringBuilder(s);
    int l = 0;
    int r = s.length() - 1;

    while (l < r) {
      while (l < r && !vowels.contains("" + sb.charAt(l)))
        ++l;
      while (l < r && !vowels.contains("" + sb.charAt(r)))
        --r;
      sb.setCharAt(l, s.charAt(r));
      sb.setCharAt(r, s.charAt(l));
      ++l;
      --r;
    }

    return sb.toString();
  }
}

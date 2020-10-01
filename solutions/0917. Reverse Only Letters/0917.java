class Solution {
  public String reverseOnlyLetters(String S) {
    StringBuilder ans = new StringBuilder(S);

    for (int i = 0, j = S.length() - 1; i < j; ++i, --j) {
      while (i < j && !Character.isLetter(S.charAt(i)))
        ++i;
      while (i < j && !Character.isLetter(S.charAt(j)))
        --j;
      ans.setCharAt(i, S.charAt(j));
      ans.setCharAt(j, S.charAt(i));
    }

    return ans.toString();
  }
}
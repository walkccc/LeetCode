class Solution {
  public int countValidWords(String sentence) {
    int ans = 0;

    for (final String token : sentence.trim().split("\\s+"))
      if (isValid(token))
        ++ans;

    return ans;
  }

  private boolean isValid(final String token) {
    int countHyphen = 0;
    for (int i = 0; i < token.length(); ++i) {
      final char c = token.charAt(i);
      if (Character.isDigit(c))
        return false;
      if (c == '-') {
        if (i == 0 || !Character.isLowerCase(token.charAt(i - 1)))
          return false;
        if (i + 1 == token.length() || !Character.isLowerCase(token.charAt(i + 1)))
          return false;
        if (++countHyphen > 1)
          return false;
      } else if (c == '!' || c == '.' || c == ',') {
        if (i != token.length() - 1)
          return false;
      }
    }
    return true;
  }
}

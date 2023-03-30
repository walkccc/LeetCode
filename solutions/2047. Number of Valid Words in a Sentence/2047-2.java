class Solution {
  public int countValidWords(String sentence) {
    final String regex = "[a-z]*([a-z]-[a-z])?[a-z]*[!,.]?";
    int ans = 0;

    for (final String token : sentence.trim().split("\\s+"))
      if (token.matches(regex))
        ++ans;

    return ans;
  }
}

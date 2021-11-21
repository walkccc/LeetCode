class Solution {
  public int countValidWords(String sentence) {
    int ans = 0;
    final String regex = "[a-z]*([a-z]-[a-z])?[a-z]*[!,.]?";

    for (final String token : sentence.trim().split("\\s+"))
      if (token.matches(regex))
        ++ans;

    return ans;
  }
}

class Solution {
  public long countVowels(String word) {
    long ans = 0;

    for (int i = 0; i < word.length(); ++i)
      if (isVowel(word.charAt(i)))
        ans += (i + 1) * (long) (word.length() - i);

    return ans;
  }

  private boolean isVowel(char c) {
    return "aeiou".indexOf(c) != -1;
  }
}

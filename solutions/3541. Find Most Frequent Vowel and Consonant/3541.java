class Solution {
  public int maxFreqSum(String s) {
    int[] count = new int[26];
    int maxVowel = 0;
    int maxConsonant = 0;

    for (final char c : s.toCharArray())
      ++count[c - 'a'];

    for (final char c : s.toCharArray())
      if (isVowel(c))
        maxVowel = Math.max(maxVowel, count[c - 'a']);
      else
        maxConsonant = Math.max(maxConsonant, count[c - 'a']);

    return maxVowel + maxConsonant;
  }

  private boolean isVowel(char c) {
    return "aeiou".indexOf(c) != -1;
  }
}

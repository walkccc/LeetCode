class Solution {
  public int[] vowelStrings(String[] words, int[][] queries) {
    int[] ans = new int[queries.length];
    // prefix[i] := the number of the first i words that start with and end in a vowel
    int[] prefix = new int[words.length + 1];

    for (int i = 0; i < words.length; ++i)
      prefix[i + 1] += prefix[i] + (startsAndEndsWithVowel(words[i]) ? 1 : 0);

    for (int i = 0; i < queries.length; ++i) {
      final int l = queries[i][0];
      final int r = queries[i][1];
      ans[i] = prefix[r + 1] - prefix[l];
    }

    return ans;
  }

  private boolean startsAndEndsWithVowel(final String word) {
    return isVowel(word.charAt(0)) && isVowel(word.charAt(word.length() - 1));
  }

  private boolean isVowel(char c) {
    return "aeiou".indexOf(c) != -1;
  }
}

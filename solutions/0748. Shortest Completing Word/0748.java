class Solution {
  public String shortestCompletingWord(String licensePlate, String[] words) {
    String ans = "****************";
    int[] count = new int[26];

    for (char c : licensePlate.toCharArray())
      if (Character.isLetter(c))
        ++count[Character.toLowerCase(c) - 'a'];

    for (final String word : words)
      if (word.length() < ans.length() && isMatch(word, count))
        ans = word;

    return ans;
  }

  private boolean isMatch(final String word, int[] count) {
    int[] wordCount = new int[26];

    for (char c : word.toCharArray())
      ++wordCount[c - 'a'];

    for (int i = 0; i < 26; ++i)
      if (wordCount[i] < count[i])
        return false;

    return true;
  }
}
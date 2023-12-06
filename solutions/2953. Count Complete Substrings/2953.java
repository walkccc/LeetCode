class Solution {
  public int countCompleteSubstrings(String word, int k) {
    final int uniqueLetters = word.chars().boxed().collect(Collectors.toSet()).size();
    int ans = 0;

    for (int windowSize = k; windowSize <= k * uniqueLetters && windowSize <= word.length();
         windowSize += k) {
      ans += countCompleteStrings(word, k, windowSize);
    }

    return ans;
  }

  // Returns the number of complete substrings of `windowSize ` of the `word`.
  private int countCompleteStrings(final String word, int k, int windowSize) {
    int res = 0;
    int countLetters = 0; // the number of letters in the running substring
    int[] count = new int[26];

    for (int i = 0; i < word.length(); ++i) {
      ++count[word.charAt(i) - 'a'];
      ++countLetters;
      if (i > 0 && Math.abs(word.charAt(i) - word.charAt(i - 1)) > 2) {
        count = new int[26];
        // Start a new substring starting at word[i].
        ++count[word.charAt(i) - 'a'];
        countLetters = 1;
      }
      if (countLetters == windowSize + 1) {
        --count[word.charAt(i - windowSize) - 'a'];
        --countLetters;
      }
      if (countLetters == windowSize)
        res += Arrays.stream(count).allMatch(freq -> freq == 0 || freq == k) ? 1 : 0;
    }

    return res;
  }
}

class Solution {
  public int[] numSmallerByFrequency(String[] queries, String[] words) {
    int[] ans = new int[queries.length];
    int[] wordsFreq = new int[words.length];

    for (int i = 0; i < words.length; ++i)
      wordsFreq[i] = f(words[i]);
    Arrays.sort(wordsFreq);

    for (int i = 0; i < queries.length; ++i) {
      final int freq = f(queries[i]);
      ans[i] = words.length - firstGreater(wordsFreq, 0, wordsFreq.length, freq);
    }

    return ans;
  }

  private int f(final String word) {
    int count = 0;
    char currentChar = 'z' + 1;

    for (final char c : word.toCharArray())
      if (c < currentChar) {
        currentChar = c;
        count = 1;
      } else if (c == currentChar) {
        ++count;
      }

    return count;
  }

  private int firstGreater(int[] nums, int l, int r, int value) {
    while (l < r) {
      final int m = (l + r) / 2;
      if (nums[m] > value)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }
}

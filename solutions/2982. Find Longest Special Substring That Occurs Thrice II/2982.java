class Solution {
  public int maximumLength(String s) {
    final int n = s.length();
    int ans = -1;
    int runningLen = 0;
    char prevLetter = '@';
    // counts[i][j] := the frequency of ('a' + i) repeating j times
    int[][] counts = new int[26][n + 1];

    for (final char c : s.toCharArray())
      if (c == prevLetter) {
        ++counts[c - 'a'][++runningLen];
      } else {
        runningLen = 1;
        ++counts[c - 'a'][runningLen];
        prevLetter = c;
      }

    for (int[] count : counts) {
      ans = Math.max(ans, getMaxFreq(count, n));
    }

    return ans;
  }

  // Returns the maximum frequency that occurs more than three times.
  private int getMaxFreq(int[] count, int maxFreq) {
    int times = 0;
    for (int freq = maxFreq; freq >= 1; --freq) {
      times += count[freq];
      if (times >= 3)
        return freq;
    }
    return -1;
  }
}

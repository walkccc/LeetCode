class Solution {
  public int beautySum(String s) {
    int ans = 0;

    for (int i = 0; i < s.length(); ++i) {
      int[] count = new int[26];
      for (int j = i; j < s.length(); ++j) {
        ++count[s.charAt(j) - 'a'];
        ans += Arrays.stream(count).max().getAsInt() - getMinFreq(count);
      }
    }

    return ans;
  }

  // Returns the minimum frequency > 0.
  private int getMin(int[] count) {
    int minFreq = Integer.MAX_VALUE;
    for (final int freq : count)
      if (freq > 0)
        minFreq = min(minFreq, freq);
    return minFreq;
  }
}

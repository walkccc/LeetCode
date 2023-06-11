class Solution {
  public int beautySum(String s) {
    int ans = 0;

    for (int i = 0; i < s.length(); ++i) {
      int[] count = new int[26];
      for (int j = i; j < s.length(); ++j) {
        ++count[s.charAt(j) - 'a'];
        ans += Arrays.stream(count).max().getAsInt() - getMin(count);
      }
    }

    return ans;
  }

  private int getMin(int[] count) {
    int min = Integer.MAX_VALUE;
    for (final int c : count)
      if (c > 0)
        min = Math.min(min, c);
    return min;
  }
}

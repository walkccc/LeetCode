class Solution {
  public int longestAwesome(String s) {
    int ans = 0;
    int prefix = 0; // the binary prefix
    int[] prefixToIndex = new int[1024];
    Arrays.fill(prefixToIndex, s.length());
    prefixToIndex[0] = -1;

    for (int i = 0; i < s.length(); ++i) {
      prefix ^= 1 << s.charAt(i) - '0';
      ans = Math.max(ans, i - prefixToIndex[prefix]);
      for (int j = 0; j < 10; ++j)
        ans = Math.max(ans, i - prefixToIndex[prefix ^ 1 << j]);
      prefixToIndex[prefix] = Math.min(prefixToIndex[prefix], i);
    }

    return ans;
  }
}

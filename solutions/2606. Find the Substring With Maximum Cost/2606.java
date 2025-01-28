class Solution {
  public int maximumCostSubstring(String s, String chars, int[] vals) {
    int ans = 0;
    int cost = 0;
    int[] costs = new int[26]; // costs[i] := the cost of 'a' + i

    for (int i = 0; i < 26; ++i)
      costs[i] = i + 1;

    for (int i = 0; i < chars.length(); ++i)
      costs[chars.charAt(i) - 'a'] = vals[i];

    for (final char c : s.toCharArray()) {
      cost = Math.max(0, cost + costs[c - 'a']);
      ans = Math.max(ans, cost);
    }

    return ans;
  }
}

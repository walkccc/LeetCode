class Solution {
  public int findPermutationDifference(String s, String t) {
    int ans = 0;
    int[] indices = new int[26];

    for (int i = 0; i < s.length(); ++i)
      indices[s.charAt(i) - 'a'] = i;

    for (int i = 0; i < t.length(); ++i)
      ans += Math.abs(indices[t.charAt(i) - 'a'] - i);

    return ans;
  }
}

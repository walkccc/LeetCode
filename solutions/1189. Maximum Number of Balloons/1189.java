class Solution {
  public int maxNumberOfBalloons(String text) {
    int ans = Integer.MAX_VALUE;
    int[] count = new int[26];

    for (char c : text.toCharArray())
      ++count[c - 'a'];

    for (char c : new char[] {'b', 'a', 'n'})
      ans = Math.min(ans, count[c - 'a']);

    for (char c : new char[] {'o', 'l'})
      ans = Math.min(ans, count[c - 'a'] / 2);

    return ans;
  }
}

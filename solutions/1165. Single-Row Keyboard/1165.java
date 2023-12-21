class Solution {
  public int calculateTime(String keyboard, String word) {
    int ans = 0;
    int prevIndex = 0;
    int[] letterToIndex = new int[26];

    for (int i = 0; i < keyboard.length(); ++i)
      letterToIndex[keyboard.charAt(i) - 'a'] = i;

    for (final char c : word.toCharArray()) {
      final int currIndex = letterToIndex[c - 'a'];
      ans += Math.abs(currIndex - prevIndex);
      prevIndex = currIndex;
    }

    return ans;
  }
}

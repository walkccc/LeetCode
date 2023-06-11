class Solution {
  public int countCharacters(String[] words, String chars) {
    int ans = 0;
    int[] count = new int[26];

    for (final char c : chars.toCharArray())
      ++count[c - 'a'];

    for (final String word : words) {
      int[] tempCount = count.clone();
      for (final char c : word.toCharArray())
        if (--tempCount[c - 'a'] < 0) {
          ans -= word.length();
          break;
        }
      ans += word.length();
    }

    return ans;
  }
}

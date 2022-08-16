class Solution {
  public int maxProduct(String[] words) {
    int ans = 0;
    int[] masks = new int[words.length]; // "abd" -> (1011)2

    for (int i = 0; i < words.length; ++i)
      masks[i] = getMask(words[i]);

    for (int i = 0; i < masks.length; ++i)
      for (int j = 0; j < i; ++j)
        if ((masks[i] & masks[j]) == 0)
          ans = Math.max(ans, words[i].length() * words[j].length());

    return ans;
  }

  private int getMask(final String word) {
    int mask = 0;
    for (final char c : word.toCharArray())
      mask |= 1 << c - 'a';
    return mask;
  }
}

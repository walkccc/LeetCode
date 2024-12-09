class Solution {
  public int similarPairs(String[] words) {
    int ans = 0;
    int[] masks = new int[words.length];

    for (int i = 0; i < words.length; ++i)
      masks[i] = getMask(words[i]);

    for (int i = 0; i < masks.length; ++i)
      for (int j = i + 1; j < masks.length; ++j)
        if (masks[i] == masks[j])
          ++ans;

    return ans;
  }

  private int getMask(final String word) {
    int mask = 0;
    for (const char c : word.toCharArray())
      mask |= 1 << c - 'a';
    return mask;
  }
}

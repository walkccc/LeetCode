class Solution {
  // Same as 2947. Count Beautiful Substrings I
  public int beautifulSubstrings(String s, int k) {
    final int root = getRoot(k);
    int ans = 0;
    int vowels = 0;
    int vowelsMinusConsonants = 0;
    // {(vowels, vowelsMinusConsonants): count}
    Map<Pair<Integer, Integer>, Integer> prefixCount = new HashMap<>();
    prefixCount.put(new Pair<>(0, 0), 1);

    for (final char c : s.toCharArray()) {
      if (isVowel(c)) {
        vowels = (vowels + 1) % root;
        ++vowelsMinusConsonants;
      } else {
        --vowelsMinusConsonants;
      }
      Pair<Integer, Integer> prefix = new Pair<>(vowels, vowelsMinusConsonants);
      ans += prefixCount.getOrDefault(prefix, 0);
      prefixCount.merge(prefix, 1, Integer::sum);
    }

    return ans;
  }

  private boolean isVowel(char c) {
    return "aeiou".indexOf(c) != -1;
  }

  private int getRoot(int k) {
    for (int i = 1; i <= k; ++i)
      if (i * i % k == 0)
        return i;
    throw new IllegalArgumentException();
  }
}

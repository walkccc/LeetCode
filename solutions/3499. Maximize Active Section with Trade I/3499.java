class Solution {
  public int maxActiveSectionsAfterTrade(String s) {
    List<Integer> zeroGroupLengths = new ArrayList<>();
    int maxZeroMerge = 0;

    for (int i = 0; i < s.length(); ++i) {
      if (s.charAt(i) == '0') {
        if (i > 0 && s.charAt(i - 1) == '0')
          zeroGroupLengths.set(zeroGroupLengths.size() - 1,
                               zeroGroupLengths.get(zeroGroupLengths.size() - 1) + 1);
        else
          zeroGroupLengths.add(1);
      }
    }

    for (int i = 0; i < zeroGroupLengths.size() - 1; ++i)
      maxZeroMerge = Math.max(maxZeroMerge, zeroGroupLengths.get(i) + zeroGroupLengths.get(i + 1));

    return (int) s.chars().filter(c -> c == '1').count() + maxZeroMerge;
  }
}
